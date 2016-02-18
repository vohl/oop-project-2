#include <iostream>
#include <sstream>
#include <string>
#include <utility>

#include "gtest/gtest.h"

#include "Voting.h"

// ---
// read_args
// ---

TEST(Voting, read_args_1){
  std::istringstream r("1\n\n2\nChad\nAndrew Vohl\n1 2\n2 1\n2 1");
  int v;
  voting_read_args(r, v);
  ASSERT_EQ(1, v);}

// ---
// read_cand
// ---

TEST(Voting, read_cand_1){
  std::istringstream r("3\nChad\nAndrew\nGabe");
  int v;
  voting_read_cand(r, v);
  ASSERT_EQ(3, v);}

// ---
// read_ballot
// ---

TEST(Voting, read_ballot_1){
  std::istringstream r("1 2 3\n2 1 3\n2 3 1");
  bool v = voting_read_ballot(r);
  ASSERT_EQ(1, v);}

// ---
// eval
// ---

TEST(Voting, eval_1){
  std::istringstream r("1\n\n2\nChad\nAndrew");
  int v;
  int j;
  int votes = 0;
  voting_read_args(r, v);
  voting_read_cand(r, j);
  while(voting_read_ballot(r)){
    ++votes;}
  std::string s = voting_eval(votes, j);
  ASSERT_EQ("Chad\nAndrew", s);}

// ---
// solve
// ---

TEST(Voting, solve_1){
  std::istringstream r("1\n\n2\nAndrew\nChad");
  std::ostringstream w;
  voting_solve(r, w);
  ASSERT_EQ("Andrew\nChad\n", w.str());}