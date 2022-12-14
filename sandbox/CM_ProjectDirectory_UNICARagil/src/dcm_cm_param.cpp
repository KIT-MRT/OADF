/**
 * \file dcm_cm_param.cpp
 * \brief Parameter for dcm cm
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#include "../dcm-core/dcm_core.h"

namespace dcmcmparam {

    /* Parameter for dcm cm */

    //f6b
    std::vector<int> f6 = {3872, -959, 75, -50};

    //f5b
    std::vector<int> f5 = {4075, -738, -15, -38};

    //f4b
    std::vector<int> f4 = {4163, -325, 125, 0};

    //f3b
    std::vector<int> f3 = {4163, 325, 125, 0};

    //f2b
    std::vector<int> f2 = {4075, 738, -15, 38};

    //f1b
    std::vector<int> f1 = {3872, 959, 75, 50};

    //b1b
    std::vector<int> b1 = {-465, -968, 85, -130};

    //b2b
    std::vector<int> b2 = {-667, -744, 115, -142};

    //b3b
    std::vector<int> b3 = {-749, -325, 140, 180};

    //b4b
    std::vector<int> b4 = {-749, 325, 140, 180};

    //b5b
    std::vector<int> b5 = {-667, 744, 115, 142};

    //b6b
    std::vector<int> b6 = {-465, 968, 85, 130};

    //r1b
    std::vector<int> r1 = {3869, -961, 125, -60};

    //r2b
    std::vector<int> r2 = {2900, -984, 45, -80};

    //r3b
    std::vector<int> r3 = {2100, -1000, 51, -90};

    //r4b
    std::vector<int> r4 = {1300, -999, 51, -90};

    //r5b
    std::vector<int> r5 = {500, -986, 45, -100};

    //r6b
    std::vector<int> r6 = {-471, -965, 125, -120};

    //l1b
    std::vector<int> l1 = {-471, 965, 125, 120};

    //l2b
    std::vector<int> l2 = {500, 986, 45, 100};

    //l3b
    std::vector<int> l3 = {1300, 1000, 50, 90};

    //l4b
    std::vector<int> l4 = {2100, 1000, 50, 90};

    //l5b
    std::vector<int> l5 = {2900, 984, 45, 80};

    //l6b
    std::vector<int> l6 = {3869, 961, 125, 60};

    //crb
    std::vector<int> cr = {3354, -960, 725, -90};

    //cbb
    std::vector<int> cb = {-789, 0, 310, -180};

    //clb
    std::vector<int> cl = {3354, 960, 725, 90};

    //cfb
    std::vector<int> cf = {4200, 0, 185, 0};

    // Vector of position and orientation vectors
    std::vector<std::vector<int>> ussc = {f6, f5, f4, f3, f2, f1, b1, b2, b3, b4, b5, b6, r1, r2, r3, r4, r5, r6, l1, l2, l3, l4, l5, l6};
    
}
