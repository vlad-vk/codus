//---------------------------------------------------------------------------
//  coding=cp866; version=2013013112; title="";
#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"


//---------------------------------------------------------------------------
//  ��⠭���� ���祭�� �� ������� ��� �⫠���
vd  far DebugVal(vd){
    //-----------------------------------------------------------------------
    // ��⠭���� ���祭�� �� 㪠������ ������ �� �⫠��筮� ��६�����
    if (DebValN1_M>=MAXDBB){ DebValN1_M=MAXDBB-1; }
    if (DebValN1_M<      0){ DebValN1_M=       0; }
    // �᫨ �������� ����� �� ࠢ�� ⮬�, �� ᥩ�� ��⠭�����
    if (DebValN1_M!=DebValN1_V){
        // ����⠭����� ���祭�� �� ⥪�饬 ������ �� ������������
        DBB[(_i)DebValN1_V]=DebValZS1V;
        // ��⠭����� ���� �����
        DebValN1_V =DebValN1_M;
        // ��������� ���祭�� ��⠭����������� ������
        DebValZS1V =DBB[(_i)DebValZ1_V];
        // ��⠭����� ����� ���祭��
        DebValZ1_V =DebValZ1_M;
    }
    //  �᫨ �뫮 ������� ����� ���祭��- ��⠭����� ���
    if (DebValN1_M==DebValN1_V && DebValZ1_M!=DebValZ1_V){ 
        DebValZ1_V= DebValZ1_M;
    }
    //  ����ﭭ� ��ᢠ����� 㪠������� ������ ��६����� ��������� ���祭��
        DBB[(_i)DebValN1_V]=DebValZ1_V;
    //-----------------------------------------------------------------------
    // ��⠭���� ���祭�� �� 㪠������ ������ �� �⫠��筮� ��६�����
    if (DebValN2_M>=MAXDBB){ DebValN2_M=MAXDBB-1; }
    if (DebValN2_M<      0){ DebValN2_M=       0; }
    // �᫨ �������� ����� �� ࠢ�� ⮬�, �� ᥩ�� ��⠭�����
    if (DebValN2_M!=DebValN2_V){
        // ����⠭����� ���祭�� �� ⥪�饬 ������ �� ������������
        DBB[(_i)DebValN2_V]=DebValZS2V;
        // ��⠭����� ���� �����
        DebValN2_V =DebValN2_M;
        // ��������� ���祭�� ��⠭����������� ������
        DebValZS2V =DBB[(_i)DebValZ2_V];
        // ��⠭����� ����� ���祭��
        DebValZ2_V =DebValZ2_M;
    }
    //  �᫨ �뫮 ������� ����� ���祭��- ��⠭����� ���
    if (DebValN2_M==DebValN2_V && DebValZ2_M!=DebValZ2_V){ 
        DebValZ2_V= DebValZ2_M;
    }
    //  ����ﭭ� ��ᢠ����� 㪠������� ������ ��६����� ��������� ���祭��
        DBB[(_i)DebValN2_V]=DebValZ2_V;
    //-----------------------------------------------------------------------
    // ��⠭���� ���祭�� �� 㪠������ ������ �� �⫠��筮� ��६�����
    if (DebValN3_M>=MAXDBB){ DebValN3_M=MAXDBB-1; }
    if (DebValN3_M<      0){ DebValN3_M=       0; }
    // �᫨ �������� ����� �� ࠢ�� ⮬�, �� ᥩ�� ��⠭�����
    if (DebValN3_M!=DebValN3_V){
        // ����⠭����� ���祭�� �� ⥪�饬 ������ �� ������������
        DBB[(_i)DebValN3_V]=DebValZS3V;
        // ��⠭����� ���� �����
        DebValN3_V =DebValN3_M;
        // ��������� ���祭�� ��⠭����������� ������
        DebValZS3V =DBB[(_i)DebValZ3_V];
        // ��⠭����� ����� ���祭��
        DebValZ3_V =DebValZ3_M;
    }
    //  �᫨ �뫮 ������� ����� ���祭��- ��⠭����� ���
    if (DebValN3_M==DebValN3_V && DebValZ3_M!=DebValZ3_V){ 
        DebValZ3_V= DebValZ3_M;
    }
    //  ����ﭭ� ��ᢠ����� 㪠������� ������ ��६����� ��������� ���祭��
        DBB[(_i)DebValN3_V]=DebValZ3_V;
    //-----------------------------------------------------------------------
    // ��⠭���� ���祭�� �� 㪠������ ������ �� �⫠��筮� ��६�����
    if (DebValN4_M>=MAXDBB){ DebValN4_M=MAXDBB-1; }
    if (DebValN4_M<      0){ DebValN4_M=       0; }
    // �᫨ �������� ����� �� ࠢ�� ⮬�, �� ᥩ�� ��⠭�����
    if (DebValN4_M!=DebValN4_V){
        // ����⠭����� ���祭�� �� ⥪�饬 ������ �� ������������
        DBB[(_i)DebValN4_V]=DebValZS4V;
        // ��⠭����� ���� �����
        DebValN4_V =DebValN4_M;
        // ��������� ���祭�� ��⠭����������� ������
        DebValZS4V =DBB[(_i)DebValZ4_V];
        // ��⠭����� ����� ���祭��
        DebValZ4_V =DebValZ4_M;
    }
    //  �᫨ �뫮 ������� ����� ���祭��- ��⠭����� ���
    if (DebValN4_M==DebValN4_V && DebValZ4_M!=DebValZ4_V){ 
        DebValZ4_V= DebValZ4_M;
    }
    //  ����ﭭ� ��ᢠ����� 㪠������� ������ ��६����� ��������� ���祭��
        DBB[(_i)DebValN4_V]=DebValZ4_V;
    //-----------------------------------------------------------------------
    // ��⠭���� ���祭�� �� 㪠������ ������ �� �⫠��筮� ��६�����
    if (DebValN5_M>=MAXDBB){ DebValN5_M=MAXDBB-1; }
    if (DebValN5_M<      0){ DebValN5_M=       0; }
    // �᫨ �������� ����� �� ࠢ�� ⮬�, �� ᥩ�� ��⠭�����
    if (DebValN5_M!=DebValN5_V){
        // ����⠭����� ���祭�� �� ⥪�饬 ������ �� ������������
        DBB[(_i)DebValN5_V]=DebValZS5V;
        // ��⠭����� ���� �����
        DebValN5_V =DebValN5_M;
        // ��������� ���祭�� ��⠭����������� ������
        DebValZS5V =DBB[(_i)DebValZ5_V];
        // ��⠭����� ����� ���祭��
        DebValZ5_V =DebValZ5_M;
    }
    //  �᫨ �뫮 ������� ����� ���祭��- ��⠭����� ���
    if (DebValN5_M==DebValN5_V && DebValZ5_M!=DebValZ5_V){ 
        DebValZ5_V= DebValZ5_M;
    }
    //  ����ﭭ� ��ᢠ����� 㪠������� ������ ��६����� ��������� ���祭��
        DBB[(_i)DebValN5_V]=DebValZ5_V;
    //-----------------------------------------------------------------------
    // ��⠭���� ���祭�� �� 㪠������ ������ �� �⫠��筮� ��६�����
    if (DebValN6_M>=MAXDBB){ DebValN6_M=MAXDBB-1; }
    if (DebValN6_M<      0){ DebValN6_M=       0; }
    // �᫨ �������� ����� �� ࠢ�� ⮬�, �� ᥩ�� ��⠭�����
    if (DebValN6_M!=DebValN6_V){
        // ����⠭����� ���祭�� �� ⥪�饬 ������ �� ������������
        DBB[(_i)DebValN6_V]=DebValZS6V;
        // ��⠭����� ���� �����
        DebValN6_V =DebValN6_M;
        // ��������� ���祭�� ��⠭����������� ������
        DebValZS6V =DBB[(_i)DebValZ6_V];
        // ��⠭����� ����� ���祭��
        DebValZ6_V =DebValZ6_M;
    }
    //  �᫨ �뫮 ������� ����� ���祭��- ��⠭����� ���
    if (DebValN6_M==DebValN6_V && DebValZ6_M!=DebValZ6_V){ 
        DebValZ6_V= DebValZ6_M;
    }
    //  ����ﭭ� ��ᢠ����� 㪠������� ������ ��६����� ��������� ���祭��
        DBB[(_i)DebValN6_V]=DebValZ6_V;
    //-----------------------------------------------------------------------
    // ��⠭���� ���祭�� �� 㪠������ ������ �� �⫠��筮� ��६�����
    if (DebValN7_M>=MAXDBB){ DebValN7_M=MAXDBB-1; }
    if (DebValN7_M<      0){ DebValN7_M=       0; }
    // �᫨ �������� ����� �� ࠢ�� ⮬�, �� ᥩ�� ��⠭�����
    if (DebValN7_M!=DebValN7_V){
        // ����⠭����� ���祭�� �� ⥪�饬 ������ �� ������������
        DBB[(_i)DebValN7_V]=DebValZS7V;
        // ��⠭����� ���� �����
        DebValN7_V =DebValN7_M;
        // ��������� ���祭�� ��⠭����������� ������
        DebValZS7V =DBB[(_i)DebValZ7_V];
        // ��⠭����� ����� ���祭��
        DebValZ7_V =DebValZ7_M;
    }
    //  �᫨ �뫮 ������� ����� ���祭��- ��⠭����� ���
    if (DebValN7_M==DebValN7_V && DebValZ7_M!=DebValZ7_V){ 
        DebValZ7_V= DebValZ7_M;
    }
    //  ����ﭭ� ��ᢠ����� 㪠������� ������ ��६����� ��������� ���祭��
        DBB[(_i)DebValN7_V]=DebValZ7_V;
    //-----------------------------------------------------------------------
    // ��⠭���� ���祭�� �� 㪠������ ������ �� �⫠��筮� ��६�����
    if (DebValN8_M>=MAXDBB){ DebValN8_M=MAXDBB-1; }
    if (DebValN8_M<      0){ DebValN8_M=       0; }
    // �᫨ �������� ����� �� ࠢ�� ⮬�, �� ᥩ�� ��⠭�����
    if (DebValN8_M!=DebValN8_V){
        // ����⠭����� ���祭�� �� ⥪�饬 ������ �� ������������
        DBB[(_i)DebValN8_V]=DebValZS8V;
        // ��⠭����� ���� �����
        DebValN8_V =DebValN8_M;
        // ��������� ���祭�� ��⠭����������� ������
        DebValZS8V =DBB[(_i)DebValZ8_V];
        // ��⠭����� ����� ���祭��
        DebValZ8_V =DebValZ8_M;
    }
    //  �᫨ �뫮 ������� ����� ���祭��- ��⠭����� ���
    if (DebValN8_M==DebValN8_V && DebValZ8_M!=DebValZ8_V){ 
        DebValZ8_V= DebValZ8_M;
    }
    //  ����ﭭ� ��ᢠ����� 㪠������� ������ ��६����� ��������� ���祭��
        DBB[(_i)DebValN8_V]=DebValZ8_V;
    //-----------------------------------------------------------------------
    // ��⠭���� ���祭�� �� 㪠������ ������ �� �⫠��筮� ��६�����
    if (DebValN9_M>=MAXDBB){ DebValN9_M=MAXDBB-1; }
    if (DebValN9_M<      0){ DebValN9_M=       0; }
    // �᫨ �������� ����� �� ࠢ�� ⮬�, �� ᥩ�� ��⠭�����
    if (DebValN9_M!=DebValN9_V){
        // ����⠭����� ���祭�� �� ⥪�饬 ������ �� ������������
        DBB[(_i)DebValN9_V]=DebValZS9V;
        // ��⠭����� ���� �����
        DebValN9_V =DebValN9_M;
        // ��������� ���祭�� ��⠭����������� ������
        DebValZS9V =DBB[(_i)DebValZ9_V];
        // ��⠭����� ����� ���祭��
        DebValZ9_V =DebValZ9_M;
    }
    //  �᫨ �뫮 ������� ����� ���祭��- ��⠭����� ���
    if (DebValN9_M==DebValN9_V && DebValZ9_M!=DebValZ9_V){ 
        DebValZ9_V= DebValZ9_M;
    }
    //  ����ﭭ� ��ᢠ����� 㪠������� ������ ��६����� ��������� ���祭��
        DBB[(_i)DebValN9_V]=DebValZ9_V;
    //-----------------------------------------------------------------------
    return;
}
//---------------------------------------------------------------------------
