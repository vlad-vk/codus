//----------------------------------------------------------------------------
//  coding=cp866; version=2013013112; title="";
//  ������� ���祭�� � ������� ���㫥�
vd  far InpDataD(vd){

    Mod_DI();

    DIH252A__V = BFiltr(11, DIH252A__V, 10);        // ���਩�� �஢��� ������ ���ண�
    DIS056G__V = BFiltr(12, DIS056G__V, 10);        // ���਩�� �஢��� ���1 ��� 諠��
    DIS057G__V = BFiltr(14, DIS057G__V, 10);        // ���਩�� �஢��� ���2 ��� 諠��
    DIS064G__V = BFiltr(15, DIS064G__V, 10);        // ���਩�� �஢��� ���1 諠��
    DIS065G__V = BFiltr(16, DIS065G__V, 10);        // ���਩�� �஢��� ���2 諠��

    return;
}
//----------------------------------------------------------------------------
