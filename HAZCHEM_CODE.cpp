#include <iostream>
#include <cstring>
using namespace std;
class PrintAd
{
public:
void pM(char *_c)
{
    cout << "Material: ";
    if(*_c=='1') cout << "Jets";
    else if(*_c=='2') cout << "Fog";
    else if(*_c=='3') cout << "Foam";
    else if(*_c=='4') cout << "Dry agent";
}

void pAdHe()
    {
        cout << "***Emergency action advice***";
    }

void pR(char *_c)
{
    cout << "Reactivity: ";
    if(*_c=='P'||*_c=='S'||*_c=='W'||*_c=='Y'||*_c=='Z') cout << "Can be violently reactive";
    else cout << "<<blank>>";
}

void pP(char *_c,bool *_b)
{
    cout << "Protection: ";
    if(*_c=='P'||*_c=='R'||*_c=='W'||*_c=='X') cout << "Full protective clothing must be worn";
    else if(*_b == false) cout << "Breathing apparatus, protective gloves ";
    else cout << "Breathing apparatus, protective gloves for fire only ";
}

void pC(char *_c)
{
    cout << "Containment: ";
    if(*_c=='P'||*_c=='R'||*_c=='S'||*_c=='T')  cout << "The dangerous goods may be washed down to a drain with a large quantity of water";
    else cout << "A need to avoid spillages from entering drains or water courses";
}

void pE(char *_c)
{
    cout << "Evacuation: ";
    if(*_c=='E') cout << "Consider Evacuation";
    else cout << "<<blank>>";
}

void pAdEnd()
    {
        cout << "****************************";
    }
};

class Advice : public PrintAd
{
    public:
    char cChTy;
    char cChAtr;
    char cEv;
    bool bFlag; 
    void rAd(char a,char b,char c)
    {
        cChTy=a;
        cChAtr=b;
        cEv=c;
    }
    void pAd(char cChTy,char cChAtr,char cEv,bool bFlag)
    {
        pAdHe();
        cout << "\n";
        pM(&cChTy);
        cout << "\n";
        pR(&cChAtr);
        cout << "\n";
        pP(&cChAtr,&bFlag);
        cout << "\n";
        pC(&cChAtr);
        cout << "\n";
        pE(&cEv);
        cout << "\n";
        pAdEnd();
    }
};

static bool bisHAZCHEM(string &s)
{
    if(s.size()>3|| s.size()<2) return false;
    else if(s.size()==3 && s[2]!='E') return false;
    else if(s[0]<'1' || s[0]>'4') return false;
    else
        {
            bool bF = false;
            string scCh = "PRSTWXYZ";
            for(int i=0;i<8;i++)
                if(scCh[i] == s[1]) 
                {
                    bF = true;
                    break;
                }
            return bF;    
        }
}

int main()
{
    string sCode; 
    string empty_string();
    cout << "\n";
    cout << "ENTER HAZCHEM CODE: ";
    cin >> sCode;
    if ( bisHAZCHEM(sCode) == true)
        {
        Advice a;
        a.bFlag = false;
        a.rAd(sCode[0],sCode[1],sCode[2]);

        if(a.cChAtr=='S'||a.cChAtr=='T'||a.cChAtr=='Y'||a.cChAtr=='Z')
        {
            char cCl;
            cout << "Is the " <<a.cChAtr << " reverse coloured ?\n";
            cout << "(Y with Yes, N with No): "; 
            cin >> cCl;
            if(cCl=='Y') a.bFlag = true;
        }

        cout << "\n" << "\n";
        a.pAd(a.cChTy,a.cChAtr,a.cEv,a.bFlag);
        cout << "\n" << "\n";
        }
    else cout << "Your code is illegal!!! \n"; 
    return 0;   
}
