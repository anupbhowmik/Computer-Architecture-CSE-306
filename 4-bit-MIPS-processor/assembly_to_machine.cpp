#include<bits/stdc++.h>
#include <bitset>

// t0 5 t1 1 t2 2 t3 3 t4 4 zero 0
#define T0 "0001"
#define T1 "0010"
#define T2 "0011"
#define T3 "0100"
#define T4 "0101"
#define ZERO "0000"
#define INSTRUCTION_SIZE 1

#define SUB  "0000"
#define ORI  "0001"
#define BNEQ  "0010"
#define ADDI  "0011"
#define BEQ  "0100"
#define OR  "0101"
#define SW  "0110"
#define SRL  "0111"
#define AND  "1000"
#define ANDI  "1001"
#define LW  "1010"
#define ADD  "1011"
#define SLL  "1100"
#define SUBI  "1101"
#define J  "1110"
#define NOR  "1111"

using namespace std;

int lineCount= 0;
vector<pair<string,int> > labelAddress;

vector<string> split(const string &s)
{
    vector<string> elements;
    string item = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ' || s[i] == ',' || s[i] == '\t') {
            if (item != "") {
                elements.push_back(item);
                item = "";
            }
        }
        else {
            item += s[i];
        }
    }

    if (item != "") {
        elements.push_back(item);
    }

    return elements;
}

string toHex(string str) {
    string hex = "";
    for (int i = 0; i < str.size(); i += 4) {
        string temp = str.substr(i, 4);
        if (temp == "0000") {
            hex += "0";
        } else if (temp == "0001") {
            hex += "1";
        } else if (temp == "0010") {
            hex += "2";
        } else if (temp == "0011") {
            hex += "3";
        } else if (temp == "0100") {
            hex += "4";
        } else if (temp == "0101") {
            hex += "5";
        } else if (temp == "0110") {
            hex += "6";
        } else if (temp == "0111") {
            hex += "7";
        } else if (temp == "1000") {
            hex += "8";
        } else if (temp == "1001") {
            hex += "9";
        } else if (temp == "1010") {
            hex += "a";
        } else if (temp == "1011") {
            hex += "b";
        } else if (temp == "1100") {
            hex += "c";
        } else if (temp == "1101") {
            hex += "d";
        } else if (temp == "1110") {
            hex += "e";
        } else if (temp == "1111") {
            hex += "f";
        }
    }
    return hex;
}

void pushbackLabels(string line){

    vector<string> v= split(line);
    // cout<<v[0];
    if(v[0]=="sub"||v[0]=="ori"||v[0]=="bneq"||v[0]=="addi"||
        v[0]=="beq"||v[0]=="or"||v[0]=="sw"||v[0]=="srl"||
        v[0]=="and"||v[0]=="andi"||v[0]=="lw"||v[0]=="add"||
        v[0]=="sll"||v[0]=="subi"||v[0]=="j"||v[0]=="nor");
    else {
        // cout << "line count: " << lineCount << endl;
        labelAddress.push_back(make_pair(v[0], lineCount));
    }
}

string convert(string line) {
    string instruction="";
    vector<string> v= split(line);
    // cout<<"# "<<lineCount<<endl;
    // for(int i=0; i<v.size(); i++)
    //     cout<<v[i]<<endl;



    string item = v[0];
    // instruction
    if(item=="sub") instruction+="0000";
    else if(item=="ori") instruction+="0001";
    else if(item=="bneq") instruction+="0010";
    else if(item=="addi") instruction+="0011";
    else if(item=="beq") instruction+="0100";
    else if(item=="or") instruction+="0101";
    else if(item=="sw") instruction+="0110";
    else if(item=="srl") instruction+="0111";
    else if(item=="and") instruction+="1000";
    else if(item=="andi") instruction+="1001";
    else if(item=="lw") instruction+="1010";
    else if(item=="add") instruction+="1011";
    else if(item=="sll") instruction+="1100";
    else if(item=="subi") instruction+="1101";
    else if(item=="j") instruction+="1110";
    else if(item=="nor") instruction+="1111";
    else {
        // cout << "line count: " << lineCount << endl;
        labelAddress.push_back(make_pair(item, lineCount));
        vector<string> temp;
        for (int j=1; j<v.size(); j++){
            temp.push_back(v[j]);
        }
        v=temp;
        item = v[0];
        // instruction
        if(item=="sub") instruction+="0000";
        else if(item=="ori") instruction+="0001";
        else if(item=="bneq") instruction+="0010";
        else if(item=="addi") instruction+="0011";
        else if(item=="beq") instruction+="0100";
        else if(item=="or") instruction+="0101";
        else if(item=="sw") instruction+="0110";
        else if(item=="srl") instruction+="0111";
        else if(item=="and") instruction+="1000";
        else if(item=="andi") instruction+="1001";
        else if(item=="lw") instruction+="1010";
        else if(item=="add") instruction+="1011";
        else if(item=="sll") instruction+="1100";
        else if(item=="subi") instruction+="1101";
        else if(item=="j") instruction+="1110";
        else if(item=="nor") instruction+="1111";
    }


    // R format : sub, or, and, add, nor
    if((instruction=="0000")||(instruction=="0101")||(instruction=="1000")||(instruction=="1011")||(instruction=="1111")) {

        if (v[2]=="$t0") instruction+=T0;
        else if (v[2]=="$t1") instruction+=T1;
        else if (v[2]=="$t2") instruction+=T2;
        else if (v[2]=="$t3") instruction+=T3;
        else if (v[2]=="$t4") instruction+=T4;
        else if (v[2]=="$zero") instruction+=ZERO;
        // instruction+=" "; //for debugging

        if (v[3]=="$t0") instruction+=T0;
        else if (v[3]=="$t1") instruction+=T1;
        else if (v[3]=="$t2") instruction+=T2;
        else if (v[3]=="$t3") instruction+=T3;
        else if (v[3]=="$t4") instruction+=T4;
        else if (v[3]=="$zero") instruction+=ZERO;
        // instruction+=" "; //for debugging

        if (v[1]=="$t0") instruction+=T0;
        else if (v[1]=="$t1") instruction+=T1;
        else if (v[1]=="$t2") instruction+=T2;
        else if (v[1]=="$t3") instruction+=T3;
        else if (v[1]=="$t4") instruction+=T4;
        else if (v[1]=="$zero") instruction+=ZERO;

        return instruction;
    }

    // S format : srl, sll
    else if((instruction=="0111")||(instruction=="1100")){

        if (v[2]=="$t0") instruction+=T0;
        else if (v[2]=="$t1") instruction+=T1;
        else if (v[2]=="$t2") instruction+=T2;
        else if (v[2]=="$t3") instruction+=T3;
        else if (v[2]=="$t4") instruction+=T4;
        else if (v[2]=="$zero") instruction+=ZERO;
        // instruction+=" "; //for debugging

        if (v[1]=="$t0") instruction+=T0;
        else if (v[1]=="$t1") instruction+=T1;
        else if (v[1]=="$t2") instruction+=T2;
        else if (v[1]=="$t3") instruction+=T3;
        else if (v[1]=="$t4") instruction+=T4;
        else if (v[1]=="$zero") instruction+=ZERO;
        // instruction+=" "; //for debugging

        int const_int=stoi(v[3]);
        string const_str="0000";

        for(int j=0; const_int>0; j++) {
            const_str[const_str.size()-j-1]=(const_int%2)?'1':'0';
            const_int= const_int/2;
        }

        instruction+=const_str;

        return instruction;
    }

    // I format constant : ori, addi, andi, subi
    else if((instruction=="0001")||(instruction=="0011")||(instruction=="1001")||(instruction=="1101")){

        if (v[2]=="$t0") instruction+=T0;
        else if (v[2]=="$t1") instruction+=T1;
        else if (v[2]=="$t2") instruction+=T2;
        else if (v[2]=="$t3") instruction+=T3;
        else if (v[2]=="$t4") instruction+=T4;
        else if (v[2]=="$zero") instruction+=ZERO;
        // instruction+=" "; //for debugging

        if (v[1]=="$t0") instruction+=T0;
        else if (v[1]=="$t1") instruction+=T1;
        else if (v[1]=="$t2") instruction+=T2;
        else if (v[1]=="$t3") instruction+=T3;
        else if (v[1]=="$t4") instruction+=T4;
        else if (v[1]=="$zero") instruction+=ZERO;
        // instruction+=" "; //for debugging

        int const_int=stoi(v[3]);
        cout<<const_int<<endl;
//        string const_str="";

        string const_str = bitset<4>(const_int).to_string();


//        char str_32[32];
//        sprintf(str_32, "%032b", const_int);
//        for(int i = 28; i < 32; i++)
//        {
//            cout<<str_32[i];
//            const_str += str_32[i];
//        }
//        cout<<endl;


        instruction+=const_str;

        return instruction;
    }

    // I format control : beq, bneq
    else if((instruction=="0100")||(instruction=="0010")){

        if (v[2]=="$t0") instruction+=T0;
        else if (v[2]=="$t1") instruction+=T1;
        else if (v[2]=="$t2") instruction+=T2;
        else if (v[2]=="$t3") instruction+=T3;
        else if (v[2]=="$t4") instruction+=T4;
        else if (v[2]=="$zero") instruction+=ZERO;
        // instruction+=" "; //for debugging

        if (v[1]=="$t0") instruction+=T0;
        else if (v[1]=="$t1") instruction+=T1;
        else if (v[1]=="$t2") instruction+=T2;
        else if (v[1]=="$t3") instruction+=T3;
        else if (v[1]=="$t4") instruction+=T4;
        else if (v[1]=="$zero") instruction+=ZERO;
        // instruction+=" "; //for debugging

        // v3 is label, fetch the line number

        int bAddress;
        for(int j=0; j<labelAddress.size(); j++){
                // cout << "j " << j << endl;
        // cout << labelAddress[j].first << endl;
            if(labelAddress[j].first == v[3] + ":") {
                bAddress=labelAddress[j].second;
            }
        }


        int const_int=(bAddress-lineCount-1)*INSTRUCTION_SIZE; //+1?
        string const_str = bitset<4>(const_int).to_string();

        instruction+=const_str;

        return instruction;
    }

    // I format memory : sw, lw
    else if((instruction=="0110")||(instruction=="1010")){

        string constant;
        stringstream ss2(v[2]);
        if (getline(ss2,item,'(')) {
            constant=item;
        }
        if (getline(ss2,item,')')) {
            if (item=="$t0") instruction+=T0;
            else if (item=="$t1") instruction+=T1;
            else if (item=="$t2") instruction+=T2;
            else if (item=="$t3") instruction+=T3;
            else if (item=="$t4") instruction+=T4;
            else if (item=="$zero") instruction+=ZERO;
        }

        if (v[1]=="$t0") instruction+=T0;
        else if (v[1]=="$t1") instruction+=T1;
        else if (v[1]=="$t2") instruction+=T2;
        else if (v[1]=="$t3") instruction+=T3;
        else if (v[1]=="$t4") instruction+=T4;
        else if (v[1]=="$zero") instruction+=ZERO;
        // instruction+=" "; //for debugging

        int const_int=stoi(constant)*INSTRUCTION_SIZE;
        string const_str = bitset<4>(const_int).to_string();

        instruction+=const_str;

        return instruction;
    }

    // J format : j
    else if((instruction=="1110")){

        int jAddress;
        for(int j=0; j<labelAddress.size(); j++){
            // cout << "j " << j << endl;
            // cout << labelAddress[j].first << endl;
            if(labelAddress[j].first == v[1] + ":") {
                jAddress=labelAddress[j].second;
            }
        }


        // cout << jAddress;
        int const_int=jAddress*INSTRUCTION_SIZE;
        string const_str = bitset<8>(const_int).to_string();

        instruction+=const_str;

        instruction+="0000";

        return instruction;
    }

    else return instruction;
}

int main ()
{
    string line;
    ifstream fin ("assembly.txt");
    ofstream fout ("machine.txt");
    fout << "v2.0 raw" << endl;
    if (fin.is_open()) {
        while (getline (fin,line)) {
            // lineCount++;
            // cout<<"AAAA";
            pushbackLabels(line);
            lineCount++;
        }
        fin.close();

        for(int i = 0; i < labelAddress.size(); i++){
            cout << labelAddress[i].first << ", " << labelAddress[i].second << endl;
        }

        fin.open("assembly.txt");
        lineCount=0;
        while (getline (fin,line)) {
            // lineCount++;
            string str_bin=convert(line);
//            string str_hex=toHex(str_bin);
            fout<<str_bin<<endl;
            lineCount++;
        }
        fin.close();
    }
    else cout<<"Unable to open file"<<endl;
    fout.close();
    return 0;
}
