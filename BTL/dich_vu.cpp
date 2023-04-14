#include "danh_sach.cpp"

class DV{
    private:
        string tdv;
        int dg;
    public:
        DV(){}
        DV(string tdv, int dg);
        ~DV(){}
        
        friend istream& operator>>(istream &is, DV* &a);

        friend ostream& operator<<(ostream &os, DV* a);

        void setTdv(string tdv);
        string getTdv();

        void setDg(int dg);
        int getDg();
};


DV :: DV(string tdv, int dg){
    this -> tdv = tdv;
    this -> dg = dg;
}

istream& operator>>(istream &is, DV* &a){
    cout << "Ten dich vu: "; getline(is, a -> tdv);
    cout << "Don gia: "; is >> a -> dg;
    return is;
}   

ostream& operator<<(ostream &os, DV* a){
    os << '|' << setw(25) << a -> tdv;
    os << '|' << setw(15) << a -> dg << '|' << endl;
    //os << '|' << setfill('=') << setw(132) << '|' << setfill(' ') << endl;
    return os;
} 

void DV :: setTdv(string tdv){
    this -> tdv = tdv;
}
string DV :: getTdv(){
    return tdv;
}

void DV :: setDg(int dg){
    this -> dg = dg;
}
int DV :: getDg(){
    return dg;
}

void ds_dvu(istream &is, Ds* &ds_dv){
    int x, i = 0;
    hoi_dvu();
    cout << "\n\tLua chon: "; is >> x;
    
    init(ds_dv);
    if (x == 0) ds_dv = NULL;
    else{
        DV *dv;
        do{
            dv = new DV;
            is.ignore();
            cout << "\n\tDich vu thu " << i + 1 << endl;
            is >> dv;
            last_list(ds_dv, dv);
            i++;
            hoi_nhap();
            cout << "\n\tLua chon: "; is >> x;
        }while(x == 1);
    }
}