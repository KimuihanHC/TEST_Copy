object MainFrm: TMainFrm
  Left = -1404
  Top = 129
  Width = 1258
  Height = 902
  Caption = 'MainFrm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 960
    Top = 136
    Width = 35
    Height = 13
    Caption = 'LOT ID'
  end
  object Label2: TLabel
    Left = 960
    Top = 32
    Width = 70
    Height = 13
    Caption = 'APPLICATION'
  end
  object Label3: TLabel
    Left = 960
    Top = 8
    Width = 61
    Height = 13
    Caption = 'transactionId'
  end
  object Label4: TLabel
    Left = 960
    Top = 56
    Width = 75
    Height = 13
    Caption = 'EQUIPMENTID'
  end
  object Label5: TLabel
    Left = 960
    Top = 80
    Width = 62
    Height = 13
    Caption = 'IPADDRESS'
  end
  object BitBtn1: TBitBtn
    Left = 224
    Top = 0
    Width = 75
    Height = 25
    Caption = 'serverConnect'
    TabOrder = 0
    OnClick = BitBtn1Click
  end
  object lboxLog0: TListBox
    Left = 768
    Top = 376
    Width = 457
    Height = 361
    ImeName = '??? ?? ??? (IME 2000)'
    ItemHeight = 13
    TabOrder = 1
    OnClick = lboxLog0Click
  end
  object GridReport: TStringGrid
    Left = 0
    Top = 56
    Width = 250
    Height = 681
    ColCount = 1
    DefaultColWidth = 690
    DefaultRowHeight = 16
    FixedCols = 0
    RowCount = 3
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 2
  end
  object edt_SendData: TEdit
    Left = 0
    Top = 32
    Width = 681
    Height = 21
    TabOrder = 3
  end
  object etn_REQUEST_LINK_TEST: TButton
    Left = 768
    Top = 0
    Width = 185
    Height = 25
    Caption = 'REQUEST_LINK_TEST'
    TabOrder = 4
    OnClick = etn_REQUEST_LINK_TESTClick
  end
  object Button2: TButton
    Left = 64
    Top = 0
    Width = 75
    Height = 25
    Caption = 'Client Connect'
    TabOrder = 5
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 144
    Top = 0
    Width = 75
    Height = 25
    Caption = 'Client DisConnect'
    TabOrder = 6
    OnClick = Button3Click
  end
  object Button5: TButton
    Left = 688
    Top = 32
    Width = 75
    Height = 25
    Caption = 'Custum'
    TabOrder = 7
    OnClick = Button5Click
  end
  object edt_Port: TLMDSpinEdit
    Left = 0
    Top = 0
    Width = 57
    Height = 21
    MaxValue = 50000
    TabOrder = 8
    Value = 5000
  end
  object chk_NoReturn: TCheckBox
    Left = 304
    Top = 8
    Width = 97
    Height = 17
    Caption = 'no return'
    TabOrder = 9
  end
  object btn_REQUEST_ALARM_LIST: TButton
    Left = 768
    Top = 32
    Width = 185
    Height = 25
    Caption = 'REQUEST_ALARM_LIST'
    TabOrder = 10
    OnClick = btn_REQUEST_ALARM_LISTClick
  end
  object btn_REQUEST_UNITID_READ: TButton
    Left = 768
    Top = 128
    Width = 185
    Height = 25
    Caption = 'REQUEST_UNITID_READ'
    TabOrder = 11
    OnClick = btn_REQUEST_UNITID_READClick
  end
  object btn_REQUEST_SET_DATETIME: TButton
    Left = 768
    Top = 64
    Width = 185
    Height = 25
    Caption = 'REQUEST_SET_DATETIME'
    TabOrder = 12
    OnClick = btn_REQUEST_SET_DATETIMEClick
  end
  object btn_REQUEST_TERMINAL_MESSAGE: TButton
    Left = 768
    Top = 96
    Width = 185
    Height = 25
    Caption = 'REQUEST_TERMINAL_MESSAGE'
    TabOrder = 13
    OnClick = btn_REQUEST_TERMINAL_MESSAGEClick
  end
  object GridRequest: TStringGrid
    Left = 256
    Top = 56
    Width = 250
    Height = 681
    ColCount = 1
    DefaultColWidth = 690
    DefaultRowHeight = 16
    FixedCols = 0
    RowCount = 3
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 14
  end
  object GridReply: TStringGrid
    Left = 512
    Top = 56
    Width = 250
    Height = 681
    ColCount = 1
    DefaultColWidth = 690
    DefaultRowHeight = 16
    FixedCols = 0
    RowCount = 3
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 15
  end
  object edt_LOTID: TEdit
    Left = 1032
    Top = 128
    Width = 121
    Height = 21
    TabOrder = 16
    Text = 'LOT_TEST'
  end
  object edt_APPLICATION: TEdit
    Left = 1032
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 17
    Text = 'APPLICATION_TEST'
  end
  object edt_transactionId: TEdit
    Left = 1032
    Top = 0
    Width = 121
    Height = 21
    TabOrder = 18
    Text = 'ec4682e8-00ed-4bac'
  end
  object edt_EQUIPMENTID: TEdit
    Left = 1032
    Top = 48
    Width = 121
    Height = 21
    TabOrder = 19
    Text = 'EES'
  end
  object edt_IPADDRESS: TEdit
    Left = 1032
    Top = 72
    Width = 121
    Height = 21
    TabOrder = 20
    Text = '127.0.0.1'
  end
  object Timer1: TTimer
    Interval = 1
    OnTimer = Timer1Timer
    Left = 736
  end
  object ServerSocket1: TServerSocket
    Active = False
    Port = 0
    ServerType = stNonBlocking
    Left = 672
  end
  object ClientSocket: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 0
    OnLookup = ClientSocketLookup
    OnConnecting = ClientSocketConnecting
    OnConnect = ClientSocketConnect
    OnDisconnect = ClientSocketDisconnect
    OnRead = ClientSocketRead
    OnWrite = ClientSocketWrite
    OnError = ClientSocketError
    Left = 704
  end
end
