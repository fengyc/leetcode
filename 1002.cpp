#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string> &A) {
        vector<vector<char>> m('z' - 'a' + 1);
        for (int i = 0; i < m.size(); i++) {
            m[i] = vector<char>(A.size());
        }
        for (int i = 0; i < A.size(); i++) {
            int len = A[i].length();
            for (int j = 0; j < len; j++) {
                char c = A[i][j];
                m[c - 'a'][i] += 1;
            }
        }
        vector<string> r;
        for (int i = 0; i < m.size(); i++) {
            auto miniCount = *min_element(m[i].begin(), m[i].end());
            while (miniCount--) {
                string s;
                s.push_back('a' + i);
                r.push_back(s);
            }
        }
        return r;
    }
};

int main() {
    Solution s;
    vector<string> a = {"dbcdjbedfchcbhbecbadeaefefhcaagfghjaidaadeaabaaegj",
                        "hfacgbgcieccadeejddegjffejdjegejbaddaiabdhahbjaiba",
                        "igfaddihhceieadjgjhefaibcfcichcdecjcihfhcgfjeihidf",
                        "jaehjjibbhfdcjjdhecicefjjjdabibahgdaeibfefbbffhjja",
                        "degddigjijggagjgaaeeegfiahhcghbefcbdabeehbihjdeabi",
                        "bjdfedddebaifgadhgdhfjjdafajhiabbjjiidhcdaagajiafh",
                        "ihfjgjjcfeebebjgihdejjdheaeeddiajffjjdbfcfdaabgcei",
                        "jdbhhhigagieacgdabbchegdaefgeebaccdeajiifgfecbdgig",
                        "djhghabfejhcgbdejfcafjbagecbdggehaaddicgejhdgdahaf",
                        "hbaaccbffecibeiabdfeggbahbiehjiejifjjjbbbiiejcejdf",
                        "fadeddbhjehehhjiiehigjdaaiaaebjdaicbefacedfcgbegge",
                        "djhidhibeghjfbdgabgeejgedifdageichiijachhjfeihfieb",
                        "jdiagceichahjbjadhagegbbedhijhgefhfcbhdeefeahghfde",
                        "chhbbaeaeacaccbjiegfadfhabbchjggidahbgdhcadafjfifa",
                        "cdiabdbeaeefjiaadigdgiihajgcbghcfdhicjjfeiciaidjfh",
                        "gfehabegchgidgjbhdighfjbeajhdfaebificjaeahiajjgeab",
                        "agafjbjjhadjaichgfihehdhfaiiaffbijeahegjgfcidhhbed",
                        "gchagffchcjjadhbhhjfiiagejchbgjabadjcbdigdfdfabgee",
                        "ciacjdahajifafhbfbdaddbgbddedhjbbbdbbbfhcidfcbiijg",
                        "dbjjbajjgehcbgfaibjjcbigaijdjaagbfbfcjebahjchdfacg",
                        "bgfifecddgcfefijhccjiaiedhaeahihehiaedjfebejceibid",
                        "hiiigbiddhhejdebjcgjgdfiaijieibbaiibecbjigadejaibj",
                        "hafbbjafdjahdhdfiafedjjdgjghcfffcjedgjeffbeahfgbcf",
                        "bfcjigdiadjhfjjbghcdhchgaiefdijgcbbcjfaehccgddigah",
                        "aehfeiccfieaihijcgfahceadeiffefiegciageeaieghadgda",
                        "eafcdbagdafjdbicbabhihfhiefdiehhiiijigfhajfcbgajff",
                        "ecgdieegbfcijifhgicihhfhgbebgbjiiegbbfhijbcbecgigd",
                        "idhjgaccgaaieidbeidbcadhidhdddgjceccjgehjcidebeidi",
                        "bchhdjiiacccidhhcbchehcaddeccfecbcedidhhbjcigddhfg",
                        "ieddgabeciffjfchdggifjcebadchbdcdgiagefhecifgifdcj",
                        "bedcfhjehehdhafeadbdffbadjhgefjdchjghjedhgadihaedc",
                        "cfhcigdaaaddfjifaadejdgdfdfdhfebicfedcefbcgbbdbibh",
                        "jbddeaghjegebciaihfjffceiaehgaeecijefafficbajehgej",
                        "dbejheeaeadbaifegcjjhahggdbgjbeieghbeijjedjdbfiecc",
                        "dgdbefabibgeehgbdjggidagdfhjdgahbjidgejjfgcafcjddf",
                        "hcbaggjggcbcgjbceihbghdhbediacdfgfheghddecedddjggf",
                        "cdhhaaieachbfgcigidjfjcihecdegifedhadgacieciihafhf",
                        "hhicegfcdihbddjaibadeacbjdjjhjdeegjjaedgjegbbbbifg",
                        "bjcggafgaajegfcihfaicfhcdfdhgfegjfcbadighbciadhcfd",
                        "cabdajhgciaihgdccghbjcbgfighjideehbejjhhihgdjebgje",
                        "caaafahejcbedgibhadcfddaejhhaaicejefeghjhijcbfaegd",
                        "fggbheafgcbgdcfibiajdachcifhcfdfebbfcjfgefebebbdcc",
                        "gdiabbdaicaijehcjhhibbeeidjdjicdbddiaacciehehdbhch",
                        "ddbahiacdhccafecfhihfhdeicghdjbfbdehcjdhjhjehdfjhc",
                        "hadjggchcjdfaaicggigjgjaeegjfccccejeghbfcgajeccfee",
                        "ghcafaieijddfiebcibdccjijafiieeidjdiadbcjhbdjaeiec",
                        "gdfjagafhcaihhejfjcjecccfbcidhcidffebcigjdbafjgieh",
                        "ifafgibebjghgiaachefhggeibejfdhfaiciighejbiahiihii",
                        "caecdaaihahejaidgcecejgcdfhhdeghjacgeaefhjbijbbhgh",
                        "hhfdeajjijgeechaieehfcfjaaaadjbejibjfajijcfhicbjhb"};

    auto r = s.commonChars(a);

    return 0;
}