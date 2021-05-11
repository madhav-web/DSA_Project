#include <iostream>
using namespace std;
class States
{
    public:
    string name;
    string a[30];
    string b[30];
    string c[30];
    int ranke;
};
int deleteElement(string arr[], int n, string x);
int main()
{
    States srinagar, shimla, chandigarh, delhi, jaipur;
    States *p1, *p2, *p3, *p4, *p5;
    p1 = &srinagar;
    p2 = &shimla;
    p3 = &chandigarh;
    p4 = &delhi;
    p5 = &jaipur;
    States *st[5] = {p1, p2, p3, p4, p5};


    srinagar.ranke = 0;
    srinagar.name = "Srinagar";
    srinagar.c[0] = "Person1";
    srinagar.c[1] = "Person2";
    srinagar.c[2] = "Person3";
    srinagar.b[0] = "Person4";
    srinagar.b[1] = "Person5";

    shimla.ranke = 1;
    shimla.name = "Shimla";
    shimla.a[0] = "Person6";
    shimla.b[0] = "Person7";
    shimla.c[0] = "Person8";

    chandigarh.ranke = 2;
    chandigarh.name = "Chandigarh";
    chandigarh.b[0] = "Person9";
    chandigarh.a[0] = "Person10";
    chandigarh.a[1] = "Person11";
    chandigarh.c[0] = "Person12";
    chandigarh.c[1] = "Person13";
    chandigarh.c[2] = "Person14";

    delhi.ranke = 3;
    delhi.name = "Delhi";
    delhi.b[0] = "Person15";
    delhi.c[0] = "Person16";
    delhi.c[1] = "Person17";

    jaipur.ranke=4;
    jaipur.name = "Jaipur";
    jaipur.b[0] = "Person18";
    jaipur.b[1] = "Person19";
    jaipur.a[0] = "Person20";


    // Main function//
    string to, from;
    cout << "From: ";
    cin >> from;
    cout <<endl;
    cout <<"To: ";
    cin>>to;
    cout <<endl;

    int to_ind, from_ind;
    for(int i=0; i<5; ++i)
    {
        if((*st[i]).name == from)
        {
            from_ind = (*st[i]).ranke;
        }
        if((*st[i]).name == to)
        {
            to_ind = (*st[i]).ranke;
        }
    }
    cout<<endl;
    cout<<endl;
    States *loc[10] = {};
    int k = 0;

    if(from_ind < to_ind)
    {
        cout<<"Going from: "<<(*st[from_ind]).name<<endl;
        loc[k] = st[from_ind];
        ++k;
        for(int j = from_ind+1; j<to_ind; ++j)
        {
            cout<< "via: "<<(*st[j]).name<<endl;
            loc[k] = st[j];
            ++k;
        }
        cout <<"to: "<< (*st[to_ind]).name<<endl;
        loc[k] = st[to_ind];
    }
    if(to_ind < from_ind)
    {
        cout<<"Going from: "<<(*st[from_ind]).name<<endl;
        loc[0] = st[from_ind];
        ++k;
        for(int m = from_ind-1; to_ind< m; --m)
        {
            cout<< "via: "<<(*st[k]).name<<endl;
            loc[m] = st[k];
            ++k;
        }
        cout <<"to: "<< (*st[to_ind]).name<<endl;
        loc[k] = st[to_ind];
    }
    int length = sizeof(loc)/sizeof(loc[0]);
    for(int o = 0; 0<length-1; o = ++o)
    {
        int z = o+1;
        if((*loc[o]).ranke < (*loc[z]).ranke)
        {
            if(sizeof((*loc[o]).c) != 0)
            {
                cout << (*loc[o]).c[0]<< " will do transportation from "<< (*loc[o]).name<< " to "<<(*loc[z]).name<<endl;
                string x = (*loc[o]).c[0];

                int p = o+1;
                int lenz = sizeof((*loc[p]).b)/sizeof((*loc[p]).b[0]);
                int position = lenz;
                (*loc[p]).b[position-1] = (*loc[o]).c[0];
                int len = sizeof((*loc[o]).c)/sizeof((*loc[o]).c[0]);
                deleteElement((*loc[o]).c, len, x);
                len = len - 1;
            }
            if(sizeof((*loc[o]).b) != 0)
            {
                int len = sizeof((*loc[o]).b)/sizeof((*loc[o]).b[0]);
                string x = (*loc[o]).b[0];
                deleteElement((*loc[o]).b, len, x);
                len = len - 1;
            }
        }
    }

}
int deleteElement(string arr[], int n, string x)
{
   int i;
   for (i=0; i<n; i++)
      if (arr[i] == x)
         break;

   if (i < n)
   {
     n = n - 1;
     for (int j=i; j<n; j++)
        arr[j] = arr[j+1];
   }

   return n;
}
