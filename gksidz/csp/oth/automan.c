//---------------------------------------------------------------------------
#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "other_e.h"

//---------------------------------------------------------------------------
//  �몫�祭�� �ᯮ���⥫�� �� ���室� � ०��� ������<>�������
vd  far AutoManM(vd){

    // �᫨ ���ﭨ� ���� ����������- ���� �������� �� �����⨥ ���
    // �ᯮ���⥫��, �易���� � �⨬ ���箬
    // � �᫨ ��ꥪ�, �ࠢ�塞� ��ॢ����� ���箬, ���� �᭮���
    // � ࠡ�� ॣ����- ���� �������� �� �몫�祭�� ॣ����

    // ��.���� 諠�� N1
    if(DIR010___V != DIR010S){
       REG01R___M  = OFF;
       DON011___V  = OFF; DON012___V = OFF;
       if(DIR010___V==OFF){ Message(122); }
       else               { Message(123); }
    } 

    // ��.���� 諠�� N2
    if(DIR020___V != DIR020S){
       REG01R___M  = OFF;
       DON021___V  = OFF; DON022___V = OFF;
       if(DIR020___V==OFF){ Message(124); }
       else               { Message(125); }
    }

    // ���ᥩ� 諠��  N3
    if(DIR031___V != DIR031S){
       REG01R___M  = OFF;
       DON031___V  = OFF; DON032___V = OFF;
       if(DIR031___V==OFF){ Message(126); }
       else               { Message(127); }
    }

    // ���ᥩ� 諠��  N2
    if(DIR041___V != DIR041S){
       REG01R___M  = OFF;
       DON041___V  = OFF; DON042___V = OFF;
       if(DIR041___V==OFF){ Message(128); }
       else               { Message(129); }
    }

    // ���ᥩ� 諠��  N1
    if(DIR051___V != DIR051S){
       REG01R___M  = OFF;
       DON051___V  = OFF; DON052___V = OFF;
       if(DIR051___V==OFF){ Message(130); }
       else               { Message(131); }
    }

    // ᡮ୨� �������� & ᡮ୨� ����- �몫���� ॣ���� �����窨 ����
    if(DIR061___V != DIR061S){
       REG02R___M  = OFF;
       DON061___V  = OFF;  DON201___V = OFF;  
       if(DIR061___V==OFF){ Message(132); }
       else               { Message(133); }
    }

    // ��蠫�� ��室�� ��
    if(DIR070___V != DIR070S){
       REG03R___M  = OFF;
       DON071___V  = OFF;  DON081___V = OFF;  DON082___V=OFF; 
       if(DIR070___V==OFF){ Message(134); }
       else               { Message(135); }
    }

    // ᪫�� 楬���
    if(DIR100___V != DIR100S){
       REG05R___M  = OFF;
       DON101___V  = OFF;  DON102___V = OFF;
       if(DIR100___V==OFF){ Message(136); }
       else               { Message(137); }
    }

    // ������������ ���饣� N1
    if(DIR110___V != DIR110S){
       DON111___V  = OFF; DON112___V = OFF;  
       if(DIR110___V==OFF and CHAN_GOM1V == ON){ STEP04 = 4; }
       if(DIR110___V==OFF){ Message(138); }
       else               { Message(139); }
    }

    // ������������ ���饣� N2
    if(DIR120___V != DIR120S){
       DON121___V  = OFF;  DON122___V = OFF;
       if(DIR120___V == OFF and CHAN_GOM2V == ON){ STEP04 = 4; }
       if(DIR120___V==OFF){ Message(164); }
       else               { Message(165); }
    }

    // ���⨫��� �ᯨ�樨 ���饣�
    if(DIR131___V != DIR131S){
       DON131___V  = OFF;
       if(DIR131___V==OFF){ Message(166); }
       else               { Message(167); }
    }

    // 譥� �ᯨ�樨 ���饣�
    if(DIR130___V != DIR130S){
       DON132___V  = OFF;
       if(DIR130___V==OFF){ Message(168); }
       else               { Message(169); }
    }

    // ���⨫��� �ᯨ�樨 楬���
    if(DIR161___V != DIR161S){
       DON161___V  = OFF;
       if(DIR161___V==OFF){ Message(170); }
       else               { Message(171); }
    }

    // 譥� �ᯨ�樨 楬���
    if(DIR160___V != DIR160S){
       DON162___V = OFF;
       if(DIR160___V==OFF){ Message(172); }
       else               { Message(173); }
    }

    // �㭪�� ���饣�
    if(DIR140___V != DIR140S){
       REG06R___M  = OFF;
       DON141___V  = OFF;  DON142___V = OFF;  DON143___V = OFF;
       DON150___V  = OFF;  DON151___V = OFF;  DON152___V = OFF;
       if(DIR140___V==OFF){ Message(174); }
       else               { Message(175); }
    }

    // �㭪�� 楬���
    if(DIR170___V != DIR170S){
       REG06R___M  = OFF;
       DON171___V  = OFF;  DON172___V = OFF;  DON173___V = OFF;
       DON180___V  = OFF;  DON181___V = OFF;  DON182___V = OFF;
       if(DIR170___V==OFF){ Message(176); }
       else               { Message(177); }
    }

    // ������ ��宣�
    if(DIR190___V != DIR190S){
       REG06R___M  = OFF;
       DON191___V  = OFF;  DON192___V = OFF;  DON193___V = OFF;
       if(DIR190___V==OFF){ Message(178); }
       else               { Message(179); }
    }

    // ��蠫�� ��室��
    if(DIR210___V != DIR210S){
       DON211___V  = OFF;  DON212___V = OFF;
       if(DIR210___V==OFF){ Message(190); }
       else               { Message(191); }
    }

    // ��蠫�� 諠��
    if(DIR220___V != DIR220S){
       REG07R___M  = OFF;
       DON221___V  = OFF;  DON222___V = OFF;  DON223___V = OFF;
       if(DIR220___V==OFF){ Message(192); }
       else               { Message(193); }
    }

    // ������ ���ண�
    if(DIR230___V != DIR230S){
       REG07R___M  = OFF;
       DON202___V  = OFF;  DON203___V = OFF; 
       DON231___V  = OFF;  DON232___V = OFF;  
       if(DIR230___V==OFF){ Message(120); }   // �㪠 
       else               { Message(121); }   // ��⮬��
    }

    // ������� ����-���
    if(DIR270___V != DIR270S){
       REG10R___M  = OFF;
       DON272___V = OFF;  DON274___V = OFF;
       if(DIR270___V==OFF){ Message(198); }   // �㪠 
       else               { Message(199); }   // ��⮬��
    }

    // ��蠫�� ��.��ᯥ���� ����� ������
    if(DIR280___V != DIR280S){
       DON281___V  = OFF;   
       DON285___V  = OFF;   
       DON286___V  = OFF;   
       DON291___V  = OFF;   
       if(DIR280___V==OFF){ Message(584); }   // �㪠 
       else               { Message(585); }   // ��⮬��
    }

    // ��蠫�� ��.��ᯥ���� ����� ������
    if(DIR300___V != DIR300S){
       REG10R___M  = OFF;
       DON301___V  = OFF;   
       if(DIR300___V==OFF){ Message(582); }   // �㪠 
       else               { Message(583); }   // ��⮬��
    }

    // ����
    if(DIR310___V != DIR310S){
       DON31A___V  = OFF;   
       DON311___V  = OFF; DON312___V = OFF; 
       DON313___V  = OFF; DON314___V = OFF;
       DON316___V  = OFF; DON317___V = OFF;
       if(DIR310___V==OFF){ Message(586); }   // �㪠 
       else               { Message(587); }   // ��⮬��
    }

    // ��������� ���ﭨ� ���祩
    DIR010S=DIR010___V, DIR020S=DIR020___V, DIR031S=DIR031___V;
    DIR041S=DIR041___V, DIR051S=DIR051___V, DIR061S=DIR061___V;
    DIR070S=DIR070___V, DIR100S=DIR100___V, DIR110S=DIR110___V,
    DIR120S=DIR120___V, DIR130S=DIR130___V, DIR140S=DIR140___V;
    DIR160S=DIR160___V, DIR170S=DIR170___V, DIR190S=DIR190___V,
    DIR200S=DIR200___V, DIR210S=DIR210___V, DIR220S=DIR220___V;
    DIR230S=DIR230___V, 
    DIR270S=DIR270___V, DIR280S=DIR280___V, DIR290S=DIR290___V;
    DIR300S=DIR300___V, DIR310S=DIR310___V;
    DIR131S=DIR131___V, DIR161S=DIR161___V;
    return;
}
//---------------------------------------------------------------------------
