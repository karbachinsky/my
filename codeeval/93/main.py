#!/usr/bin/perl -w

use strict;
use Data::Dumper;

print Dumper(@ARGV);

=old
my $file = $ARGV[0];
open(F, $ARGV[0]) or die;

while(my $line = <F>) {
    print join('', map {uc($_)} split(/(\W)/, $line));
}
=cut
