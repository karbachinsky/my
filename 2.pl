use warnings;
use strict;

use Data::Dumper;

my @array = (1,2,4,7,5,6,3,2);
my @result;


sub get_sign {
    my ($a, $b) = @_;

    my $sign = int($b > $a);  
    print "a = $a   b = $b   sign = $sign\n";
    return $sign;
}


sub flush {
    my ($tmp_arrayref, $result_ref) = @_;

    my @found = @$tmp_arrayref;
    
    push @$result_ref, \@found; 
}

my @tmp = ($array[0], $array[1]);
my $sign = get_sign(@array[0,1]);

foreach my $i (2 .. scalar(@array)-1) {
    print "val = $array[$i]\n";
    my $cur_sign = get_sign(@array[$i-1,$i]);

    $sign = $cur_sign unless defined $sign;

    if ($cur_sign == $sign) {
        push @tmp, $array[$i];
        next;
    }

    flush(\@tmp, \@result);
    
    $sign = undef;
    @tmp = ($array[$i]);
}

flush(\@tmp, \@result) if (@tmp); 


print Dumper(\@result);

