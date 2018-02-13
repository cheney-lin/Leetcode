
class Solution {
    public:
        char nextGreatestLetter(vector<char>& letters, char target) {
            if (letters.size() <= 0) {
                return 0;
            }
            char min_letter = letters[0];
            char min_letter_gt_target = target;
            for (size_t i = 0; i < letters.size(); ++i) {
                min_letter = min(letters[i], min_letter);
                if (letters[i] > target) {
                    if (min_letter_gt_target <= target) {
                        min_letter_gt_target = letters[i];
                    } else {
                        min_letter_gt_target = min(min_letter_gt_target, letters[i]);
                    }
                }
            }
            return min_letter_gt_target > target ? min_letter_gt_target : min_letter;
        }
};
