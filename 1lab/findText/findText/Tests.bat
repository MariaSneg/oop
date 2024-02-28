chcp 1251
 
SET MyProgram="%~1"
 
if %MyProgram% == "" (
	echo Please specify path to program
	exit /B 1
)

rem "$(ProjectDir)Tests.bat" "$(TargetPath)"
echo Find in empty file
%MyProgram% test1.txt "world" >"%TEMP%\output.txt" 
echo 1
fc output1.txt "%TEMP%\output.txt" > nul || goto err
echo Test 1 passed

echo Find in english text
%MyProgram% test2.txt "time" >"%TEMP%\output.txt" 
fc output2.txt "%TEMP%\output.txt" || goto err
echo Test 2 passed

echo Find in russion text
%MyProgram% test3.txt "вам" >"%TEMP%\output.txt"
fc output3.txt "%TEMP%\output.txt" || goto err
echo Test 3 passed

REM Тесты прошли упешно
echo All tests passed sucessfuly
exit /B 0

:err
echo Test faild
exit /b 1