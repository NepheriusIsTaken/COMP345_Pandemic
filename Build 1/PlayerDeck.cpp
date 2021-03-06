#include "PlayerDeck.h"



PlayerDeck::PlayerDeck()
{
}


PlayerDeck::~PlayerDeck()
{
}

// We return NULL if there are no more cards, which is a lose condition for the game.
Card* PlayerDeck::draw()
{
	if (this->deck->size() > 0) {
		return this->drawTop();
	}
	return NULL;
}

void PlayerDeck::toDiscard(Card * card)
{
	this->discard->push_back(card);
}
// Adding the event cards before shuffling. This step is needed before cards are distributed to the players.
// This needs to happen before we add the epidemic cards in the deck.
void PlayerDeck::initialize()
{
	for (unsigned i = 1; i < 6; ++i) {
		this->add(new EventCard(i));
	}
	random_shuffle(this->deck->begin(), this->deck->end());
}

// This method divides the deck in numberOfEpidemicCards portions, then add an epidemic card to each portion, shuffle them individually and add them together.
void PlayerDeck::shuffleEpidemic(int numberOfEpidemicCards)
{
	// We want to know the base number of cards in each divisions.
	int division = this->deck->size() / numberOfEpidemicCards;

	// Here we want to know how many divisions will have 1 more card. Ex: if we have 3.33333 cards in our split decks and 3 decks, then we could have a deck
	// of 4 cards and two decks of 3.
	double decimals = ((this->deck->size() / numberOfEpidemicCards) - division)*numberOfEpidemicCards;
	vector<int> separate;
	// We create a vector and add the number of cards in each split deck portions.
	for (int i = 0; i < numberOfEpidemicCards; ++i) {
		separate.push_back(division + 1);
		if (decimals > 0) {
			separate.at(separate.size() - 1) += 1;
		}
	}
	// We shuffle that vector so that the beginning or the end doesn't always have more cards.
	random_shuffle(separate.begin(), separate.end());
	int lastLoop = 0;

	// Here we use the information above to know where to insert the epidemic cards in the deck and 
	// where to divide the deck to shuffle each separate portions.
	for (int i = 0; i < numberOfEpidemicCards; ++i) {
		this->deck->insert(this->deck->begin() + lastLoop, new EpidemicCard());
		random_shuffle(this->deck->begin() + lastLoop, this->deck->begin() + lastLoop + separate.at(i) + 1);
		lastLoop += separate.at(i);
	}
}

int PlayerDeck::getSize()
{
	return this->deck->size();
}
