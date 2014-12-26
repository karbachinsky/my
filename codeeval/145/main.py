#!/usr/bin/python


"""
CodeEval issue #145.
https://www.codeeval.com/open_challenges/145/
Author: I. Karbachinsky <igorkarbachinsky@mail.ru>
"""

from __future__ import print_function
from itertools import combinations
import sys


class State(object):
    def __init__(self, name, num_votes, issues):
        self.name = name
        self.num_votes = num_votes
        self.issues = issues    
        
        self.num_votes_threshold = self.num_votes / 2 

    def get_issue_num_votes(self, issue):
        return 

    def is_win_combination(self, combination):
        """
        Check whether certain issues combination wins in this state
        """
        num_recived_votes = 0
        for issue, _ in combination:
            num_recived_votes += self.issues.get(issue, 0)

        return num_recived_votes > self.num_votes_threshold

    def __repr__(self):
        return unicode(self.issues)

class PresidentWinner(object):
    """
    Class for performing strategy
    """
    MIN_VOTES_REQUIRED = 270
    #MIN_VOTES_REQUIRED = 27

    def __init__(self, filename):
        """
        Parses input file and saves all the necessary information to internal structures.
        """
        with open(filename, 'r') as f:
            # Getting number of issues
            _, self.num_issues = self._parse_file_line(f.readline())    
            f.readline()

            # Getting issues costs information
            self.issues_costs = dict()

            for i in xrange(self.num_issues):
                issue, cost = self._parse_file_line(f.readline())    
                self.issues_costs[issue] = cost    

            f.readline()

            # Getting information about each state
            self.states = list()
            state_name, state_num_votes, state_issues = None, 0, dict()

            for line in f:
                line = line.rstrip()
                if not line:
                    self.states.append(
                        State(state_name, state_num_votes, state_issues)
                    )
                    state_name, state_num_votes, state_issues = None, 0, dict()
                    continue
                
                if state_name is None:
                    state_name = line
                    # yes, we read another one line!
                    _, state_num_votes = self._parse_file_line(f.next()) 
                    continue

                # Information about each issues votes for state
                issue, num_issue_votes = self._parse_file_line(line) 
                state_issues[issue] = num_issue_votes

            if state_name:
                self.states.append(
                    State(state_name, state_num_votes, state_issues)
                )

      
    @staticmethod 
    def _parse_file_line(line):
        """
        Parses one line of input file and returns corresponding key and integer value.
        """
        key, value = line.split(':', 2)
        value = int(value.strip())
        return key, value 

    def _check_combination(self, combination):
        """
        Check whether combination is ok and return success status and cost of it
        """
        num_recived_votes = 0
        for state in self.states:
            if state.is_win_combination(combination):
                num_recived_votes += state.num_votes

        return num_recived_votes >= self.MIN_VOTES_REQUIRED

    def get_combination_cost(self, combination):
        return sum(map(lambda c: c[1], combination)) 
    
    def perform(self):
        """
        Algorithm. Checking all possible issues combinations in order of growing issues combinations complexity.
        """ 
        win_combination, win_combination_cost = None, None
        for num_issues_to_check in xrange(self.num_issues):
            for combination in combinations(self.issues_costs.items(), num_issues_to_check): 
                is_good =  self._check_combination(combination) 
                combination_cost = self.get_combination_cost(combination)

                if is_good:
                    if win_combination is None or combination_cost < win_combination_cost:
                        win_combination = combination
                        win_combination_cost = combination_cost
   
            # If at least on combination found we dont need to check more expensive combinations 
            if win_combination:
                break

        if not win_combination:
            raise RuntimeError("Something worng! Win combination doesn't exist!")

        self.display(win_combination)

    def display(self, combination):
        # Lexicographic sort of issues names
        for issue, _ in sorted(combination, key=lambda a: a[0]): 
            print(issue) 


def main():
    try:
        winner = PresidentWinner(sys.argv[1])      
        winner.perform()
    except RuntimeError as e:
        print(unicode(e))


if __name__ == '__main__':
    main()

