//---------------------------------------------------------------------------
#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "other_e.h"

//---------------------------------------------------------------------------
//  ��⠭���� ���祭�� �� ������� ��� �⫠���
vd  far DebugVal(vd){
    //-----------------------------------------------------------------------
    // ��⠭���� ���祭�� �� 㪠������ ������ �� �⫠��筮� ��६�����
    if (D03ValN1_M>=MAXDBB){ D03ValN1_M=MAXDBB-1; }
    if (D03ValN1_M<      0){ D03ValN1_M=       0; }
    // �᫨ �������� ����� �� ࠢ�� ⮬�, �� ᥩ�� ��⠭�����
    if (D03ValN1_M!=D03ValN1_V){
        // ����⠭����� ���祭�� �� ⥪�饬 ������ �� ������������
        DBB[(_i)D03ValN1_V]=D03ValZS1V;
        // ��⠭����� ���� �����
        D03ValN1_V =D03ValN1_M;
        // ��������� ���祭�� ��⠭����������� ������
        D03ValZS1V =DBB[(_i)D03ValZ1_V];
        // ��⠭����� ����� ���祭��
        D03ValZ1_V =D03ValZ1_M;
    }
    //  �᫨ �뫮 ������� ����� ���祭��- ��⠭����� ���
    if (D03ValN1_M==D03ValN1_V && D03ValZ1_M!=D03ValZ1_V){ 
        D03ValZ1_V= D03ValZ1_M;
    }
    //  ����ﭭ� ��ᢠ����� 㪠������� ������ ��६����� ��������� ���祭��
        DBB[(_i)D03ValN1_V]=D03ValZ1_V;
    //-----------------------------------------------------------------------
    // ��⠭���� ���祭�� �� 㪠������ ������ �� �⫠��筮� ��६�����
    if (D03ValN2_M>=MAXDBB){ D03ValN2_M=MAXDBB-1; }
    if (D03ValN2_M<      0){ D03ValN2_M=       0; }
    // �᫨ �������� ����� �� ࠢ�� ⮬�, �� ᥩ�� ��⠭�����
    if (D03ValN2_M!=D03ValN2_V){
        // ����⠭����� ���祭�� �� ⥪�饬 ������ �� ������������
        DBB[(_i)D03ValN2_V]=D03ValZS2V;
        // ��⠭����� ���� �����
        D03ValN2_V =D03ValN2_M;
        // ��������� ���祭�� ��⠭����������� ������
        D03ValZS2V =DBB[(_i)D03ValZ2_V];
        // ��⠭����� ����� ���祭��
        D03ValZ2_V =D03ValZ2_M;
    }
    //  �᫨ �뫮 ������� ����� ���祭��- ��⠭����� ���
    if (D03ValN2_M==D03ValN2_V && D03ValZ2_M!=D03ValZ2_V){ 
        D03ValZ2_V= D03ValZ2_M;
    }
    //  ����ﭭ� ��ᢠ����� 㪠������� ������ ��६����� ��������� ���祭��
        DBB[(_i)D03ValN2_V]=D03ValZ2_V;
    //-----------------------------------------------------------------------
    // ��⠭���� ���祭�� �� 㪠������ ������ �� �⫠��筮� ��६�����
    if (D03ValN3_M>=MAXDBB){ D03ValN3_M=MAXDBB-1; }
    if (D03ValN3_M<      0){ D03ValN3_M=       0; }
    // �᫨ �������� ����� �� ࠢ�� ⮬�, �� ᥩ�� ��⠭�����
    if (D03ValN3_M!=D03ValN3_V){
        // ����⠭����� ���祭�� �� ⥪�饬 ������ �� ������������
        DBB[(_i)D03ValN3_V]=D03ValZS3V;
        // ��⠭����� ���� �����
        D03ValN3_V =D03ValN3_M;
        // ��������� ���祭�� ��⠭����������� ������
        D03ValZS3V =DBB[(_i)D03ValZ3_V];
        // ��⠭����� ����� ���祭��
        D03ValZ3_V =D03ValZ3_M;
    }
    //  �᫨ �뫮 ������� ����� ���祭��- ��⠭����� ���
    if (D03ValN3_M==D03ValN3_V && D03ValZ3_M!=D03ValZ3_V){ 
        D03ValZ3_V= D03ValZ3_M;
    }
    //  ����ﭭ� ��ᢠ����� 㪠������� ������ ��६����� ��������� ���祭��
        DBB[(_i)D03ValN3_V]=D03ValZ3_V;
    //-----------------------------------------------------------------------
    // ��⠭���� ���祭�� �� 㪠������ ������ �� �⫠��筮� ��६�����
    if (D03ValN4_M>=MAXDBB){ D03ValN4_M=MAXDBB-1; }
    if (D03ValN4_M<      0){ D03ValN4_M=       0; }
    // �᫨ �������� ����� �� ࠢ�� ⮬�, �� ᥩ�� ��⠭�����
    if (D03ValN4_M!=D03ValN4_V){
        // ����⠭����� ���祭�� �� ⥪�饬 ������ �� ������������
        DBB[(_i)D03ValN4_V]=D03ValZS4V;
        // ��⠭����� ���� �����
        D03ValN4_V =D03ValN4_M;
        // ��������� ���祭�� ��⠭����������� ������
        D03ValZS4V =DBB[(_i)D03ValZ4_V];
        // ��⠭����� ����� ���祭��
        D03ValZ4_V =D03ValZ4_M;
    }
    //  �᫨ �뫮 ������� ����� ���祭��- ��⠭����� ���
    if (D03ValN4_M==D03ValN4_V && D03ValZ4_M!=D03ValZ4_V){ 
        D03ValZ4_V= D03ValZ4_M;
    }
    //  ����ﭭ� ��ᢠ����� 㪠������� ������ ��६����� ��������� ���祭��
        DBB[(_i)D03ValN4_V]=D03ValZ4_V;
    //-----------------------------------------------------------------------
    return;
}
//---------------------------------------------------------------------------
