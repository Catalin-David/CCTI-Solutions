#include <iostream>
#include <vector>
#include <limits>

enum Suit {Diamond, Club, Heart, Spade};

enum CardValue {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

class Card
{
private:
    bool available = true;
protected:
    Suit suit;
    CardValue cardValue;
public:
    Card(Suit suit, CardValue cardValue)
    {
        this->suit = suit;
        this->cardValue = cardValue;
    }

    virtual int faceValue()
    {
        switch(cardValue)
        {
        case Ace:
            return 1;
        case Two :
            return 2;
        case Three:
            return 3;
        case Four:
            return 4;
        case Five:
            return 5;
        case Six:
            return 6;
        case Seven:
            return 7;
        case Eight:
            return 8;
        case Nine:
            return 9;
        case Ten:
            return 10;
        case Jack:
            return 11;
        case Queen:
            return 12;
        default:
            return 13;
        }
    }

    virtual int value() = 0;

    virtual Suit getSuit()
    {
        return suit;
    }

    virtual bool isAvailable()
    {
        return available;
    }

    virtual void markUnavailable()
    {
        available = false;
    }

    virtual void markAvailable()
    {
        available = true;
    }
};

template<typename T, typename std::enable_if<std::is_base_of<Card, T>::value>::type* = nullptr>
class Deck
{
private:
    std::vector<T*> cards;
    int dealtIndex = 0;
public:
    void setCards(std::vector<int>& newCards)
    {
        cards.clear();
        std::move(newCards.begin(), newCards.end(), std::back_inserter(cards));
    }

    int remainingCards()
    {
        return cards.size() - dealtIndex;
    }

    /*
    void shuffle(){..}
    vector<T*> dealCards(int number){..}
    T* dealCard(){}
    */
};

template<typename T, typename std::enable_if<std::is_base_of<Card, T>::value>::type* = nullptr>
class Hand
{
protected:
    std::vector<T*> cards;

public:
    int score()
    {
        int score = 0;
        for(T* card: cards)
        {
            score += card->value();
        }
        return score;
    }

    void addCard(T* card)
    {
        cards.push_back(card);
    }
};

class BlackJackCard: public Card
{
public:
    BlackJackCard(Suit s, CardValue v) : Card(s, v) {}

    virtual int value()
    {
        if(isAce())
        {
            return 1;
        }
        else if(isFaceCard())
        {
            return 10;
        }
        else
        {
            return faceValue();
        }
    }

    virtual bool isAce()
    {
        return faceValue() == 1;
    }

    virtual bool isFaceCard()
    {
        int value = faceValue();
        return 11 <= value && value <= 13;
    }

    virtual int minValue()
    {
        if(isAce())
        {
            return 1;
        }
        else
        {
            return value();
        }
    }

    virtual int maxValue()
    {
        if(isAce())
        {
            return 11;
        }
        else
        {
            return value();
        }
    }
};

class BlackJackHand: public Hand<BlackJackCard>
{
public:
    BlackJackHand()
    {

    }

    virtual int score()
    {
        std::vector<int> scores = possibleScores();
        int maxUnder = std::numeric_limits<int>::min();
        int minOver = std::numeric_limits<int>::max();

        for(int score: scores)
        {
            if(score > 21 && score < minOver)
            {
                minOver = score;
            }
            else if(score <= 21 && score > maxUnder)
            {
                maxUnder = score;
            }
        }

        return maxUnder == std::numeric_limits<int>::min() ? minOver : maxUnder;
    }

private:
    std::vector<int> possibleScores()
    {
        std::vector<int> scores;
        for(BlackJackCard* card : cards)
        {
            addCardToScoreList(card, scores);
        }
        return scores;
    }

    void addCardToScoreList(BlackJackCard* card, std::vector<int>& scores)
    {
        if(scores.empty())
        {
            scores.push_back(card->minValue());
            if(card->minValue() != card->maxValue())
            {
                scores.push_back(card->maxValue());
            }
            return;
        }
        for(int i=0; i<scores.size(); i++)
        {
            int score = scores[i];
            scores[i] += card->minValue();
            if(card->minValue() != card->maxValue())
            {
                scores.push_back(score + card->maxValue());
            }
        }
    }
public:

    virtual bool busted()
    {
        return score() > 21;
    }

    virtual bool is21()
    {
        return score() == 21;
    }

    virtual bool isBlackJack()
    {
        if(cards.size() != 2)
        {
            return false;
        }
        BlackJackCard* first = cards[0];
        BlackJackCard* second = cards[1];
        return (first->isAce() && second->isFaceCard()) || (first->isFaceCard() && second->isAce());
    }
};




int main()
{
    BlackJackHand* hand = new BlackJackHand;
    hand->addCard(new BlackJackCard(Diamond, Ace));
    hand->addCard(new BlackJackCard(Club, Seven));
    hand->addCard(new BlackJackCard(Spade, Nine));
    std::cout<<hand->score();
    return 0;
}
