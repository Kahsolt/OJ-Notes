@ECHO OFF
IF /I "%1"=="" GOTO END
IF /I "%2"=="" GOTO END
IF /I "%3"=="" GOTO END

SET FN="%1-%2.%3"
IF EXIST %FN% (
  ECHO file exists.
  GOTO END
)

echo // %DATE% > %FN%
echo // Note: >> %FN%
echo. >> %FN%

:END
