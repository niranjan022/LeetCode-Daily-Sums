class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> qp;  // Deque to maintain the order
        sort(deck.begin(), deck.end(), greater<int>());  // Sort deck in descending order
        
        for (int card : deck) {
            if (!qp.empty()) {
                // Move the last card to the front
                qp.push_front(qp.back());
                qp.pop_back();
            }
            // Add the current card to the front
            qp.push_front(card);
        }
        
        // Transfer deque elements to the result vector
        return vector<int>(qp.begin(), qp.end());
    }
};
