#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;

namespace ariel
{
    vector<int> numToArray(int num);
    string snowman(int num);

    /*
    converting the number given to an array
    */
    vector<int> numToArray(int num)
    {
        const int minimumInput = 11111111; //if the value is smaller its illegal by definition
        const int maximumInput = 44444444; //if the value is bigger it's illegal by definition
        const int minimumLegalDigit = 0;   //after substraction for working with vector consts'
        const int maximumLegalDigit = 3;
        const int exp = 10;

        if (num < minimumInput || num > maximumInput)
        {
            throw std::out_of_range{"illegal input"};
        }
        std::vector<int> ans = {0, 0, 0, 0, 0, 0, 0, 0};
        int i = 0;
        int length = (ans.size());
        length--;
        for (i = 0; i <= length; i++)
        {
            ans[length - i] = (num % exp) - 1;
            if (ans[length - i] < minimumLegalDigit || ans[length - i] > maximumLegalDigit)
            {
                throw std::out_of_range{"illegal input"};
            }
            num /= exp;
        }
        return ans;
    }

    string snowman(int num)
    {
        const std::vector<std::string> hatsTops{"      ", "  ___ ", "   _  ", "  ___ "};
        const std::vector<std::string> hatsBottoms{" _===_ ", " ..... ", "  /_\\ ", " (_*_) "};
        const std::vector<std::string> eyes{".", "o", "O", "-"};
        const std::vector<std::string> nose{",", ".", "_", " "};
        const std::vector<std::string> leftArmUpChar{" ", "\\", " ", " "};
        const std::vector<std::string> leftArmDownChar{"<", " ", "/", " "};
        const std::vector<std::string> rightArmUpChar{" ", "/", " ", " "};
        const std::vector<std::string> rightArmDownChar{">", " ", "\\", " "};
        const std::vector<std::string> torso{" : ", "] [", "> <", "   "};
        const std::vector<std::string> base{" : ", "\" \"", "___", "   "};
        const int hatIndex = 0;
        const int noseIndex = 1;
        const int leftEyeIndex = 2;
        const int rightEyeIndex = 3;
        const int leftArmIndex = 4;
        const int rightArmIndex = 5;
        const int torsoIndex = 6;
        const int baseIndex = 7;
        vector<int> array = numToArray(num);
        std::string ans;
        ans.append(hatsTops.at(array.at(hatIndex)));
        ans.append("\n");
        ans.append(hatsBottoms.at(array.at(hatIndex)));
        ans.append("\n");
        ans.append((leftArmUpChar.at(array.at(leftArmIndex))));
        ans.append("(");
        ans.append(eyes.at(array.at(leftEyeIndex)));
        ans.append(nose.at(array.at(noseIndex)));
        ans.append(eyes.at(array.at(rightEyeIndex)));
        ans.append(")");
        ans.append((rightArmUpChar.at(array.at(rightArmIndex))));
        ans.append("\n");
        ans.append((leftArmDownChar.at(array.at(leftArmIndex))));
        ans.append("(");
        ans.append(torso.at(array.at(torsoIndex)));
        ans.append(")");
        ans.append((rightArmDownChar.at(array.at(rightArmIndex))));
        ans.append("\n");
        ans.append(" (");
        ans.append(base.at(array.at(baseIndex)));
        ans.append(")");
        return ans;
    }

}