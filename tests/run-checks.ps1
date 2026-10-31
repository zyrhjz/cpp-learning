$ErrorActionPreference = 'Stop'
$PSNativeCommandUseErrorActionPreference = $false
$repoRoot = Split-Path -Parent $PSScriptRoot
$buildRoot = Join-Path $repoRoot 'build\checks'
if (-not (Get-Command cl.exe -ErrorAction SilentlyContinue)) {
    throw 'Run this script from a Visual Studio Developer PowerShell with MSVC available.'
}
New-Item -ItemType Directory -Path $buildRoot -Force | Out-Null

function Build-Example([string]$source, [string]$name, [string[]]$extraFlags = @()) {
    $exePath = Join-Path $buildRoot ($name + '.exe')
    $objPath = Join-Path $buildRoot ($name + '.obj')
    $diagnostics = & cl.exe /nologo /std:c++17 /W4 /WX /EHsc /utf-8 @extraFlags $source "/Fe:$exePath" "/Fo:$objPath" 2>&1
    if ($LASTEXITCODE -ne 0) { throw "Compile failed: $name`n$($diagnostics -join "`n")" }
    Write-Host "Compiled: $name"
}

$sources = Get-ChildItem -LiteralPath (Join-Path $repoRoot 'examples') -Recurse -File -Filter main.cpp | Sort-Object FullName
foreach ($source in $sources) { Build-Example $source.FullName $source.Directory.Name }
Build-Example (Join-Path $PSScriptRoot 'counter_checks.cpp') 'counter-11'
Build-Example (Join-Path $PSScriptRoot 'counter_checks.cpp') 'counter-12' @('/DTEST_LESSON_12')

$cases = @(
    @{ Lesson='01'; Input=''; Expected="Name: hujunzhe`nGoal:learn c plus plus.`nDay1."; Exit=0 },
    @{ Lesson='02'; Input=''; Expected="00011010`n1a`n42"; Exit=0 },
    @{ Lesson='03'; Input=''; Expected="before:10`nstock:7`n7.5"; Exit=0 },
    @{ Lesson='04'; Input='7 2'; Expected="3.50`n1"; Exit=0 },
    @{ Lesson='04'; Input='7 0'; Expected='zero'; Exit=1 },
    @{ Lesson='04'; Input='10001 2'; Expected='range error!'; Exit=1 },
    @{ Lesson='04'; Input='abc 2'; Expected='input error!'; Exit=1 },
    @{ Lesson='04'; Input='-10000 10000'; Expected="-1.00`n0"; Exit=0 },
    @{ Lesson='04'; Input='10000 -10000'; Expected="-1.00`n0"; Exit=0 },
    @{ Lesson='04'; Input='1 -10001'; Expected='range error!'; Exit=1 },
    @{ Lesson='05'; Input='-1'; Expected='invalid'; Exit=1 },
    @{ Lesson='05'; Input='0'; Expected='minor'; Exit=0 },
    @{ Lesson='05'; Input='17'; Expected='minor'; Exit=0 },
    @{ Lesson='05'; Input='18'; Expected='adult'; Exit=0 },
    @{ Lesson='05'; Input='59'; Expected='adult'; Exit=0 },
    @{ Lesson='05'; Input='60'; Expected='senior'; Exit=0 },
    @{ Lesson='05'; Input='150'; Expected='senior'; Exit=0 },
    @{ Lesson='05'; Input='151'; Expected='invalid'; Exit=1 },
    @{ Lesson='05'; Input='abc'; Expected='invalid'; Exit=1 },
    @{ Lesson='06'; Input='0'; Expected='0'; Exit=0 },
    @{ Lesson='06'; Input='1'; Expected='0'; Exit=0 },
    @{ Lesson='06'; Input='6'; Expected='12'; Exit=0 },
    @{ Lesson='06'; Input='10000'; Expected='25005000'; Exit=0 },
    @{ Lesson='06'; Input='10001'; Expected='invalid'; Exit=1 },
    @{ Lesson='06'; Input='-1'; Expected='invalid'; Exit=1 },
    @{ Lesson='06'; Input='abc'; Expected='invalid'; Exit=1 },
    @{ Lesson='07'; Input='0'; Expected='0'; Exit=0 },
    @{ Lesson='07'; Input='3 -2 4 0'; Expected='2'; Exit=0 },
    @{ Lesson='07'; Input='-3 -2 0'; Expected='0'; Exit=0 },
    @{ Lesson='07'; Input='3 abc 4 0'; Expected='1'; Exit=0 },
    @{ Lesson='07'; Input='0 2 3'; Expected='0'; Exit=0 },
    @{ Lesson='07'; Input='2 3'; Expected='2'; Exit=0 },
    @{ Lesson='07'; Input=''; Expected='0'; Exit=0 },
    @{ Lesson='07'; Input=((@('1') * 999) -join ' ') + ' 0'; Expected='999'; Exit=0; Label='999 positive values, then 0' },
    @{ Lesson='07'; Input=((@('1') * 1000) -join ' ') + ' 0'; Expected='1000'; Exit=0; Label='1000 positive values, then 0' },
    @{ Lesson='07'; Input=((@('1') * 1001) -join ' ') + ' 0'; Expected='1000'; Exit=0; Label='1001 positive values, then 0' },
    @{ Lesson='07'; Input=((@('1 -1') * 1001) -join ' ') + ' 0'; Expected='1000'; Exit=0; Label='1001 positive values interleaved with negatives' },
    @{ Lesson='09'; Input='3 8'; Expected="a:8`nb:3"; Exit=0 },
    @{ Lesson='09'; Input='-4 0'; Expected="a:0`nb:-4"; Exit=0 },
    @{ Lesson='09'; Input='-2147483648 2147483647'; Expected="a:2147483647`nb:-2147483648"; Exit=0 },
    @{ Lesson='09'; Input='abc 8'; Expected='invalid'; Exit=1 },
    @{ Lesson='09'; Input='3 abc'; Expected='invalid'; Exit=1 },
    @{ Lesson='09'; Input='3'; Expected='invalid'; Exit=1 },
    @{ Lesson='09'; Input=''; Expected='invalid'; Exit=1 },
    @{ Lesson='09'; Input='2147483648 1'; Expected='invalid'; Exit=1 },
    @{ Lesson='10'; Input=''; Expected="5`n0"; Exit=0 },
    @{ Lesson='11'; Input=''; Expected="8`ndestroy 8`ndestroy 0"; Exit=0 },
    @{ Lesson='12'; Input=''; Expected="8`ndestroy 8`ndestroy 0"; Exit=0 },
    @{ Lesson='13'; Input=''; Expected="1`n2"; Exit=0 }
)

$results = @(foreach ($case in $cases) {
    $exePath = Join-Path $buildRoot ('lesson-' + $case.Lesson + '.exe')
    $actual = (($case.Input | & $exePath) -join "`n").TrimEnd()
    $actualExit = $LASTEXITCODE
    $inputLabel = if ($case.Label) { $case.Label } elseif ($case.Input) { $case.Input } else { '(empty / no input)' }
    [PSCustomObject]@{ Test=('lesson-' + $case.Lesson); Input=$inputLabel; Expected=$case.Expected; Actual=$actual; ExpectedExit=$case.Exit; ActualExit=$actualExit; Passed=($actual -eq $case.Expected -and $actualExit -eq $case.Exit) }
})

foreach ($lesson in @('11','12')) {
    $exePath = Join-Path $buildRoot ('counter-' + $lesson + '.exe')
    $actual = (& $exePath) -join "`n"
    $actualExit = $LASTEXITCODE
    $results += [PSCustomObject]@{ Test=('counter-' + $lesson); Input='constructor, setter, increment and int limits'; Expected='counter checks passed'; Actual=$actual; ExpectedExit=0; ActualExit=$actualExit; Passed=($actualExit -eq 0 -and $actual.Contains('counter checks passed')) }
}

$results | ConvertTo-Json -Depth 4 | Set-Content -LiteralPath (Join-Path $buildRoot 'results.json') -Encoding utf8
$failed = @($results | Where-Object { -not $_.Passed })
Write-Host ("Examples compiled: {0}; checks passed: {1}/{2}" -f $sources.Count, ($results.Count - $failed.Count), $results.Count)
if ($failed.Count -gt 0) { $failed | Format-List; exit 1 }
