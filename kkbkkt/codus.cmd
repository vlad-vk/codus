# coding:cp866
#-----------------------------------------------------------------------------
#  �������� �⮣� 䠩�� ��뢠���� 18 ࠧ/ᥪ㭤� (����� ���짮��⥫�᪨� ⨪)
#  p0000 - (0) ��६���� ��饣� ���ᨢ� (���� �������)
#  l0000 - (1) ��६���� �����쭮�� ���ᨢ�
#  c0000 - ��६���� ���ᨢ� COM ����
#  n0000 - ��६���� ���ᨢ� NetBIOS
#  t0000 - ��६���� ���ᨢ� TCPIP
#  y0000 - (6) ��६���� ���ᨢ� �������� 'y'
#  x0000 - (7) �६����  ��६����
#-----------------------------------------------------------------------------


#  ����������� ����������:
#-----------------------------------------------------------------------------
   %���            = 0                      ;
   %���            = 1                      ;
   %���            = 0                      ;
   %���            = 1                      ;
   %���            = 0                      ;
   %��             = 1                      ;
#--------------------------------------------
   %������_�               = 787878         ;
   %������_�               = 454545         ;
   %������_�����           = 12             ;
   %������_����            = 56             ;
   %������_���_����        = 90             ;
   %������_�����_���       = x0031          ;
   %������_����_���        = x0032          ;
   %������_���_����_���    = x0033          ;
#--------------------------------------------
   %�������_�              = 5              ;
   %�������_�              = 12             ;
   %�������_�              = 3              ;
   %�������_S              = 19             ;
   %�������_F11            = 57             ;
   %�������_F12            = 58             ;
   %�������_ESC            = 59             ;
   %�������_ENTER          = 67             ;
   %�������_ZERO           = 0              ;
   %�������_����_������    = x0023          ;
   %�������_����_������    = x0024          ;
#--------------------------------------------
   %�������_����           = l0004          ;
   %�������_���������      = l0032          ;
   %�������_�������        = l0007          ;
   %������������_�������   = l0005          ;
   %�����������_�������    = x0030          ;
   %����_������            = l0006          ;
#--------------------------------------------
   %����_��������_�������� = l0019          ;
   %�����_�_�������_�����  = l0069          ;
   %�����_�_���_���_�����  = y0069          ;
#--------------------------------------------
   %�������_�����          = x0101          ;
   %�������_�����          = x0100          ;
   %�������_�����          = l0041          ;
   %�������_�����          = x0001          ;
   %������������           = l0043          ;
   %������������_1         = x0002          ;
   %������������_����      = x0003          ;
#--------------------------------------------
   %�����_������           = l0031          ;
   %����_��������_������   = x0025          ;
   %����_�������_��������� = l0020          ;
   %����_�������_����      = l0021          ;
   %������_����__���       = l0045          ;
   %������_�����_���       = l0046          ;
   %������_����__���       = l0047          ;
   %������_�����_���       = l0048          ;
#--------------------------------------------
   %�����_���������_������ = l0033          ;
   %���_�������_���������  = l0034          ;
   %���������_������       = l0035          ;
#--------------------------------------------


#  ������������� ����������:
#-----------------------------------------------------------------------------
#  ��।������ ��஫��
   %������_�����_���       = %������_�      ;
   %������_�����_���       = %������_�      ;
#-----------------------------------------------------------------------------
#  ���� ��� ��ப ⥪�� 䠩�� ��ᬮ�� (��� �뢮�� ��� ��ப)
   %�����_�_���_���_����� = %�����_�_�������_�����    ;
#-----------------------------------------------------------------------------
#  ��⠭���� 䫠�� ����� ᥪ㭤�
   %�������_����� = %���                    ;
if %�������_����� ! %�������_�����          ;
   %�������_����� = %���                    ;
fi                                          ;
   %�������_����� = %�������_�����          ;
#-----------------------------------------------------------------------------
#  ������ ����� ᥪ㭤�                     ;
if %�������_����� = %���                    ;
   x0047 = x0047 + 1
fi                                          ;
#----------
#  ��⠭���� ��६����� ���� ࠧ � ��砫� �ணࠬ��
if l0014 = 1                                ; 
   l0014 = 2                                ; ���� ����᪠ �ணࠬ�� CODUS
   x0046 = 0                                ; ��� �����樨 ����
   x0047 = 1                                ; ���稪 ᥪ㭤 ࠡ��� �ணࠬ��
   x0048 = 0                                ; ���� �����樨 ����
   x0049 = 1                                ; ���稪 ᥪ㭤 � �����樨 ����
   l0077 = 1
fi                                          ;
#  ����� ���� ��⪨ ࠡ��� �ணࠬ��
if x0047 = 86400                            ;
   x0047 = 1                                ;
   x0049 = 1                                ;
fi                                          ;
#-----------------------------------------------------------------------------


#  ����������� ����� "��������" ��� �������:
#-----------------------------------------------------------------------------
   %������������_���� = %����          ;
if $ErrBell1_V ! %����                 ; # �᫨ ��⠭����� 䫠� ������
   %������������_���� = %���           ;
fi                                     ;
if $ErrBell3_V ! %����                 ; 
   %������������_���� = %���           ;
fi                                     ;
if $ErrBell5_V ! %����                 ; 
   %������������_���� = %���           ;
fi                                     ;
if %������������_���� ! %����          ; # �᫨ ��⠭����� 䫠� ������ -
   %�������_����� = %�������_����� + 1 ; # ����� ⨪�
el                                     ;
   %������������  = %����              ; # ��६�� �� ����� ���� 
fi                                     ; # ��� �뢮�� �����஢������ ���窠 (!)
if %�������_�����   >  9               ;
   %�������_�����   =  0               ; # ����� ��� ᥪ㭤� ������ 
   if %������������ >  0               ; # ����ࠦ���� (�����騩 ���祪)
      %������������ =  0               ;
   el                                  ;
      if %������������_1 = 1           ;
         %������������   = 2           ;
      el                               ;
         %������������   = 1           ;
      fi                               ;
      %������������_1 = %������������  ;
   fi                                  ;
fi                                     ;
#-----------------------------------------------------------------------------


# �������� ������� � ������� �� ������:
#-----------------------------------------------------------------------------
%����_�������_��������� = 0  ;    # 䫠� ����� ���������
%����_�������_����      = 0  ;    # 䫠� ����� ����

%����_��������_������    = %����            ; # ��࠭ ����஫������ ��஫��

if %�����_������ = 3                        ; # ��࠭ "�������" (E 3)
   %����_��������_������ = %���             ;
fi                                          ;
if %�����_������ = 8                        ; # ��࠭ "������"
   %����_��������_������ = %���             ;
fi                                          ;
if %�����_������ = 4                        ; # ��࠭ "��������" | "�������"
   %����_��������_������ = %���             ;
fi                                          ;
if %�����_������ = 5                        ; # ��࠭ "������������"
   %����_��������_������ = %���             ;
fi                                          ;
#-----------------------------------------------------------------------------


#  ������� �� ������ "����1" � "����2"
#-----------------------------------------------------------------------------
if %�������_������� = %�������_F11           ; # ��࠭ ���室 �� ��࠭ "����1"
   if %������_�����_���  ! %������_����__��� ; # �᫨ �� ������ ��஫� ��� � �
      %�������_�������   = %�������_ZERO     ;
      %�������_��������� = %���              ; # ������ (������� ����⢨�)
      %�����_���������_������ = 4            ;
      %���_�������_���������  = 10           ;
      %���������_������  = %���              ;
   fi                                        ;
fi                                           ;
#---------------------------------------------
if %�������_������� = %�������_F12           ; # ��࠭ ���室 �� ��࠭ "����2"
   if %������_�����_���  ! %������_����__��� ;
      %�������_�������   = %�������_ZERO     ;
      %�������_��������� = %���              ;
      %�����_���������_������ = 4            ;
      %���_�������_���������  = 60           ;
      %���������_������  = %���              ;
   fi                                        ;
fi                                           ;
#-----------------------------------------------------------------------------


#  �� ����⨨ ������ ESC ��᫥ ������� ���� ����� ��� �����-
#  ᭨������ ��㪮��� ᨣ���
#-----------------------------------------------------------------------------
if %�����������_������� > 0                      ; # ��᫥ ����� ������ ESC 
   if %�������_�����    = %��                    ; # ����������
      %�������_�������  = %�����������_�������   ; # ����⨥ ������ 'S' ��� 
      %�����������_�������  = %�������_ZERO      ; # ���� ᨣ���� �訡��
      %�������_���������    = %���               ;
      %������������_������� = %�������_ZERO      ; # ����� ��� ��� ������ 
   fi                                            ; # ������ ���� ������
fi                                               ;
if %�������_������� = %�������_ESC               ; # �᫨ ����� ������ ESC
   %�����������_�������  = %�������_S            ; # ��⠭����� ����⨥ ������
fi                                               ; # 'S' ���  ᫥� 横��
if %������������_������� = %�������_ESC          ; # ������ ESC ������ �����
   %�����������_�������  = %�������_S            ; # ��⠭����� ����⨥ ������ 
fi                                               ; # 'S' ��� ᫥� 横��
#-----------------------------------------------------------------------------



#  �������� �������� ������� �������:
#-----------------------------------------------------------------------------
if %����_������  = %����                          ;
   if %������_�����_���  ! %������_����__���      ;
      if %����_��������_������   = %���           ;
         %����_�������_��������� = %���           ;
         %����_�������_����      = %���           ;
         if %�������_�������     = %�������_ENTER ;
            %�����_���������_������ = 5           ;
            %���_�������_���������  = 10          ;
            %���������_������    = %���           ;
         fi                                       ;
      fi                                          ;
      # �᫨ ����� ������ '�'(���������) � �� ������ ��஫�- �।�०�����
      if %�������_�������        = %�������_�     ;        
         %�������_�������        = %�������_ZERO  ;
         %�������_���������      = %���           ;
         %�����_���������_������ = 4              ;
         %���_�������_���������  = 10             ;
         %���������_������       = %���           ;
      fi                                          ;
   fi                                             ;
   if %������_�����_���  ! %������_����__���      ;
      if %����_��������_������   = 2              ;
         %����_�������_��������� = %���           ;
         %����_�������_����      = %���           ;
         if %�������_�������     = %�������_ENTER ;
            %�����_���������_������ = 7           ;
            %���_�������_���������  = 10          ;
            %���������_������    = %���           ;
         fi                                       ;
      fi                                          ;
      # �᫨ ����� ������ '�'(������������) � �� ������ ��஫�-�।�०�����
      if %�������_�������        = %�������_�     ;        
         %�������_�������        = %�������_ZERO  ;
         %�������_���������      = %���           ;
         %�����_���������_������ = 6              ;
         %���_�������_���������  = 10             ;
         %���������_������       = %���           ;
      fi                                          ;
   fi                                             ;
fi                                                ;
#-----------------------------------------------------------------------------


# ��⮬���᪠� ������� ���⮢ � ������ �� � 䠩�
# -----------------------------------------------------------------------------
%���������_���  = 7
%���������_���1 = 7
%���������_���2 = 8
%���������_���3 = 9
%���������_���  = 7

# ---------                                 ;
# ��砫� �����樨 ����                   ;
if x0046 = 0                                ;
if l0039 = %���������_���                   ; ���
if l0041 = %���������_���                   ; ���㭤�

l0007 = 0                                   ;
if l0040 = %���������_���1                  ; �����
l0007 = 446                                 ; ��� ����⮩ ������ (���� - ��⥫1)
fi                                          ; 

if l0040 = %���������_���2                  ; �����
l0007 = 447                                 ; ��� ����⮩ ������ (���� - ��⥫2)
fi                                          ;

if l0007 > 0                                ; 
l0032 = 1                                   ; ���� ����� ���� ����⮩ ������
x0046 = 1                                   ; ������騩 蠣 �����樨 ����
x0049 = x0047                               ; ����騩 ���稪 ����� ᥪ㭤�
x0048 = 1                                   ; 
fi                                          ;

fi                                          ;
fi                                          ;
fi                                          ;

# ---------
# ���� ��� ������:                          ;
if x0046 = 1                                ; ��� �����樨
if x0049 ! x0047                            ; �᫨ ��諠 ᥪ㭤�
   o_TEST_LOC_018:#1.0018#                  ;
   x0050 = l0018 - 1                        ; �।��騩 ���� ������
if x0050 < 0                                ;
   x0050 = 6                                ;
fi                                          ;
$CurDayWk_M = x0050                         ; ���� ������ �� ����� �㦭� ᣥ���஢��� ����
x0046 = 2                                   ; ������騩 蠣 �����樨 ����
x0049 = x0047 + 15                          ; ����騩 ���稪 ����� ᥪ㭤� (����� 15ᥪ ��� ��������� ��� ��६�����)
o_CurWeekDay_M:#CurDayWk_M# 
o_CurWeekDay_V:#CurDayWk_V# 
o_TEST_TMP_050:#7.0050# 
o_TEST_TMP_047:#7.0047# 
fi                                          ;
fi                                          ;

# ----------                                ;
# ������ ������ "���������" �� ��࠭�       ;
if x0046 = 2                                ; ��� �����樨
if x0049 < x0047                            ; �᫨ ��襫 ����� �� ��
l0007 = 303                                 ; ��� ����⮩ ������
l0032 = 1                                   ; ���� ����� ���� ����⮩ ������
x0046 = 3                                   ; ������騩 蠣 �����樨 ����
x0049 = x0047                               ; ����騩 ���稪 ����� ᥪ㭤�
fi                                          ;
fi                                          ;

# ---------                                 ;
# ������ ������ "������" �� ��࠭�          ;
if x0046 = 3                                ; ��� �����樨
if x0049 ! x0047                            ; �᫨ ��襫 ����� �� ��
l0007 = 716                                 ; ��� ����⮩ ������
l0032 = 1                                   ; ���� ����� ���� ����⮩ ������
x0046 = 0                                   ;
fi                                          ;
fi                                          ;

if l0040 = %���������_���3                  ;
if x0048 > 0                                ;
x0048 = 0                                   ;
l0007 = 48                                  ; ��� ����⮩ ������ (F2 - ������1)
l0032 = 1                                   ; ���� ����� ���� ����⮩ ������
fi                                          ;
fi                                          ;

if x0048 > 0                                ;
%�����_���������_������ = 8              ;
%���_�������_���������  = 10             ;
%���������_������       = %���           ;
fi                                          ;
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# ������ ���� ��� ⥪�饣� ����
x0011 = $AIF301_D_V * 0.563  ;    # ��⥫ 1
x0012 = $AIF311_D_V * 0.563  ;    # ��⥫ 2
#-----------------------------------------------------------------------------
p1075 = p0055 ;
#-----------------------------------------------------------------------------