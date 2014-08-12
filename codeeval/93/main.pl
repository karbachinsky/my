#!/usr/bin/perl -w

use strict;

open(F, $ARGV[0]) or die;

while(my $line = <F>) {
    print join('', map {ucfirst($_)} split(/(\W)/, $line));
}

=head

Codeeval task #93
Capitalizes all words in statement.

Author: I. Karbachinsky

=cut

