#!/usr/bin/perl -w

use strict;

open(F, $ARGV[0]) or die;

while(my $line = <F>) {
    print lc($line);
}

=head

Codeeval task #20
To lowercase all symbols

Author: I. Karbachinsky

=cut

