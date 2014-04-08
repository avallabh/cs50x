use strict;
use warnings;
use POSIX();

sub main {

  my ($change_due, $change_in_cents, $number_of_cents);
  my $number_of_coins = 0;

  do {
    print "How much change is owed?\n";
    $change_due = <STDIN>;
    chomp $change_due;
  } while ($change_due !~ /\A\d*(\.\d{0,2})?\z/ || $change_due < 0);

  if ($change_due == 0) {
    print "$number_of_coins\n";
  }
  else {
    $change_in_cents = $change_due * 100;

    while ($change_in_cents >= 25) {
      my $coins = POSIX::floor(($change_in_cents) / 25);
      $number_of_coins += $coins;
      $change_in_cents = $change_in_cents % 25;
    }
    while ($change_in_cents >= 10) {
      my $coins = POSIX::floor(($change_in_cents) / 10);
      $number_of_coins += $coins;
      $change_in_cents = $change_in_cents % 10;
    }
    while ($change_in_cents >= 5) {
      my $coins = POSIX::floor(($change_in_cents) / 5);
      $number_of_coins += $coins;
      $change_in_cents = $change_in_cents % 5;
    }
    while ($change_in_cents >= 1) {
      $number_of_coins += $change_in_cents;
      $change_in_cents = 0;
    }
    print "$number_of_coins\n";
  }
}

main();
