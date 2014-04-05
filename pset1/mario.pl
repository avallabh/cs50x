use strict;
use warnings;

sub main {

  my $height;

  do {
    print "Enter a height (1-23): \n";
    $height = <STDIN>;
    chomp $height;
  } while ($height =~ /\D/ || $height < 0 || $height > 23);

  if ($height == 0) {
    print "0\n";
  }

  for (my $i = 0; $i < $height; $i++) {
    for (my $j = 0; $j < $height-($i+1); $j++) {
      print " ";
    }
    for (my $k = 0; $k < $i+2; $k++) {
      print "#";
    }
    print "\n";
  }
}

main();
