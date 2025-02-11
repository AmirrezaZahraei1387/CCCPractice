#include <iostream>
#include <string>



struct BadKey{

    static constexpr char NONE {'-'};

    char key{'-'};
    char see{'-'};

    char quiet{'-'};
};

BadKey findBadKeys(const std::string& seq, const std::string& feed) {

    BadKey k{};
    int offset{0};

    for (int i{0}; i < seq.size(); ++i) {
        //std::cout<<"offset: "<<offset<<' '<<i<<std::endl;
        if (seq[i] == k.quiet)
            ++offset;

        else if (seq[i] != feed[i - offset] && seq[i] != k.key) {

            int j{i};

            while(seq[i] == seq[++j] && j < seq.size());
            j = j - i - 1;

            // check for quiet key
            if ((feed[i - offset] == seq[i + j + 1] && i + j + 1 < seq.size() && i - offset < feed.size()) ||
            (i - offset >= feed.size())) {
                // then seq[i] is the quiet key
                k.quiet = seq[i];
                //std::cout<<"quite key: "<<k.quiet<<std::endl;
                ++offset;
            } else {
                // this is the silly key!
                k.key = seq[i];
                k.see = feed[i - offset];
                //std::cout<<"key: "<<k.key<<std::endl;
                //std::cout<<"see: "<<k.see<<std::endl;
            }


        }

        if(k.key != BadKey::NONE && (k.quiet != BadKey::NONE || seq.size() == feed.size()))
            break;
    }

    return k;

}

int main(){

    std::string seq;
    std::getline(std::cin>>std::ws, seq);

    std::string feed;
    std::getline(std::cin>>std::ws, feed);

    auto ans{findBadKeys(seq, feed)};

    std::cout<<ans.key<<' '<<ans.see<<std::endl;
    std::cout<<ans.quiet<<std::endl;

    return 0;
}
