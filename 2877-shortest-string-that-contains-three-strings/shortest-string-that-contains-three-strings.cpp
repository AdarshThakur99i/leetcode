class Solution {
public:
   string check(string a,string b,string c ) {
  
       
            if(a.find(b)==string::npos) {
                int j=a.size()-1;
               
              int i=0;
              int overlap=0;
              for(int i=min(a.size(),b.size()); i>0; i--) {
                        if(a.substr(a.size()-i)==b.substr(0,i)) {
                            overlap=i;
break;
                        }

              }

              a+=b.substr(overlap);

            }
           
             
          
           if(a.find(c)==string::npos) {
                int j=a.size()-1;
             
               int i=0;
              int overlap=0;
              for(int i=min(a.size(),c.size()); i>0; i--) {
                        if(a.substr(a.size()-i)==c.substr(0,i)) {
                            overlap=i;
break;
                        }

              }

              a+=c.substr(overlap);
            }
           return a;
   }
    string minimumString(string a, string b, string c) {
         
      string one=check(a,b,c);
      string two=check(b,a,c);
      string thr=check(c,a,b);
      string fr=check(a,c,b);
      string fv=check(b,c,a);
      string sx=check(c,b,a);
      
      int mini=min({one.size(),two.size(),thr.size(),fr.size(),fv.size(),sx.size()});
      string answ=string(1e5,'z');
    if (one.size() == mini) answ = min(answ, one);
if (two.size() == mini) answ = min(answ, two);
if (thr.size() == mini) answ = min(answ, thr);
if (fr.size() == mini) answ = min(answ, fr);
if (fv.size() == mini) answ = min(answ, fv);
if (sx.size() == mini) answ = min(answ, sx);
      return answ;
    }
};

//aa