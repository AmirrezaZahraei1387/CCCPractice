//
// Created by KAVOSH on 1/10/2024.
//
#include <iostream>
#include <set>
#include <map>
#include <vector>


struct Node;


using PageMap_t = std::map<int, Node*>;
using PageFlow_t = std::vector<Node*>;


struct Node{
    int pageNum{};
    std::vector<Node*> options;
};


void init_pageMap(PageMap_t& pageMap, int pageN){
    for(int page{1}; page<=pageN; ++page){
        pageMap[page] = new Node{.pageNum = page};
    }
}


void delete_pageMap(PageMap_t& pageMap, int pageN){
    for(int page{1}; page<=pageN; ++page){
        delete pageMap[page];
    }
}


void getUserInput(PageMap_t& pageMap, int pageN, std::istream& inStream){

    int optionCount{};
    int option{};

    for(int page{1}; page <= pageN; ++page){
        inStream >> optionCount;

        for(int op{0}; op< optionCount; ++op){
            inStream >> option;

            pageMap[page]->options.push_back(pageMap[option]);
        }
    }
}


void getReachablePages(Node* node, std::set<int>& pages){
    if(pages.find(node->pageNum) == pages.end()){
        pages.insert(node->pageNum);

        for(auto a: node->options){
            getReachablePages(a, pages);
        }
    }
}


bool areAllReachable(Node* node, int pageCount){

    std::set<int> pages;
    getReachablePages(node, pages);
    return pages.size() == pageCount;
}


int findShortestPath(PageFlow_t& pages, int level = 0){

    ++level;
    std::vector<Node*> afterPages;

    for(auto page: pages){
        if(page->options.empty()){
            return level;
        } else{
            for(auto subPage: page->options){
                afterPages.push_back(subPage);
            }
        }
    }

    return findShortestPath(afterPages, level);
}


int findShortestPath(Node* node){
    PageFlow_t pageFlow{node};
    return findShortestPath(pageFlow);
}


void outputYN(bool b, std::ostream& outStream){
    outStream<<(b ? 'Y' : 'N')<<std::endl;
}


int main(){

    int pageCount{};
    std::cin>>pageCount;

    PageMap_t pageMap;

    init_pageMap(pageMap, pageCount);

    getUserInput(pageMap, pageCount, std::cin);

    bool areReachable{areAllReachable(pageMap[1], pageCount)};
    int shortestPath{findShortestPath(pageMap[1])};

    outputYN(areReachable, std::cout);
    std::cout<<shortestPath<<std::endl;

    delete_pageMap(pageMap, pageCount);
    return 0;
}