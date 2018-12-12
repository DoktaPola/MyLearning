//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//void Sort(std::vector<int>& my_v){
//    int tmp;
//    bool need_sort = true;
//    while (need_sort){
//        need_sort = false;
//        for (int second = 0; second < my_v.size() - 1; ++second){
//            if (my_v[second] > my_v[second + 1]){
//                need_sort = true;
//                tmp = my_v[second];
//                my_v[second] = my_v[second + 1];
//                my_v[second + 1] = tmp;
//            }
//        }
//    }
//}
//
//int main(){
//    std::vector<int> v = {2, 3, 1, -2, 7, 2};
////    std::vector<int> v(1000);
////    std::generate(v.begin(), v.end(), std::rand);
//    Sort(v);
//    for (auto& i: v){
//        std::cout << i << " ";
//    }
//    if (std::is_sorted(v.begin(), v.end())) {
//        std::cout << "SORTED" << std::endl;
//    } else {
//        std::cout << "NOT SORTED" << std::endl;
//    }
//}
