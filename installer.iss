; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "Rick's Tetris"
#define MyAppVersion "1.0"
#define MyAppPublisher "rickumali.com"
#define MyAppURL "http://tech.rickumali.com/tetris"
#define MyAppExeName "tetris.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppID={{296BFD7D-7626-4681-A780-5469B1064C0E}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}
InfoAfterFile=C:\cygwin\home\rumali\MinGW\tetris\README-inst.txt
OutputBaseFilename=rtsetup
Compression=lzma/Max
SolidCompression=true
PrivilegesRequired=none
OutputDir=C:\cygwin\home\rumali\MinGW\tetris
SetupIconFile=C:\cygwin\home\rumali\MinGW\tetris\rtet.ico
AppCopyright=Rick Umali, 2011
UninstallDisplayIcon={app}\tetris.exe
VersionInfoVersion=1.0
VersionInfoCompany=RickUmali.com
VersionInfoCopyright=2011
VersionInfoProductVersion=1.0.0.0

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "C:\cygwin\home\rumali\MinGW\tetris\tetris.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\cygwin\home\rumali\MinGW\tetris\help.bmp"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\cygwin\home\rumali\MinGW\tetris\rtet.bmp"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\cygwin\home\rumali\MinGW\tetris\start.bmp"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\cygwin\home\rumali\MinGW\tetris\tetris.bmp"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\cygwin\home\rumali\MinGW\tetris\VeraBd.ttf"; DestDir: "{app}"; Flags: ignoreversion
Source: C:\cygwin\home\rumali\MinGW\tetris\README.txt; DestDir: {app}; Flags: ignoreversion isreadme; 
Source: "C:\SDL_ttf-2.0.9\lib\libfreetype-6.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\SDL_ttf-2.0.9\lib\SDL_ttf.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\SDL_ttf-2.0.9\lib\zlib1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\SDL-1.2.13\bin\SDL.dll"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files
Source: C:\cygwin\home\rumali\MinGW\tetris\scoretable.pl; DestDir: {app}; 

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, "&", "&&")}}"; Flags: nowait postinstall skipifsilent
