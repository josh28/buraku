//
// Created by Josh Petite on 2019-03-03.
//

#include "player.h"

void player::addToChipTotal(int chips) {
  m_chipTotal += chips;
  m_maxChipTotal = std::max(m_maxChipTotal, m_chipTotal);
}

void player::resetRound() {
  m_hand->discard();
  m_standing = false;
  m_doublingDown = false;
}

int player::getChipTotal() const {
  return m_chipTotal;
}

std::string player::getName() const {
  return m_name;
}

std::string player::getStatus() {
  std::ostringstream stream;
  stream << getName() << std::endl;
  stream << "\tHand: ";

  bool firstCardSkipped = false;
  for (auto const& c : m_hand->getHandForDisplay()) {
    if (!firstCardSkipped) {
      stream << "H  ";
      firstCardSkipped = true;
      continue;
    }

    stream << c << " ";
  }

  stream << std::endl;
  stream << "\tChips: " << getChipTotal() << std::endl;
  stream << "\t" << m_hand->getCurrentState() << std::endl;

  return stream.str();
}

bool player::isDoublingDown() const {
  return m_doublingDown;
}

bool player::standing() const {
  return m_standing;
}

void player::receiveCard(const card &card) {
  m_hand->addCard(card);
}

void player::setDoublingDown(bool doublingDown) {
  m_doublingDown = doublingDown;
}

void player::setStanding(bool standing) {
  m_standing = standing;
}