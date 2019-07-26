
# ( cd data && cat y1 y3 y6 ye n1 n3 n6 ne ) | perl data.pl | md5sum | grep 14d8e97694a655397516b20f63e72791

use strict;
use warnings;
use IO::Compress::Deflate qw(deflate $DeflateError) ;

sub o($$)
 {die() if(100<$_[0]);
  ${$_[1]}.=pack("Q",(2**64/100)*$_[0]);
 }
my $u='';
while(<STDIN>)
 {
  if($_ !~ /^([0-9]{1,3}[.][0-9]{1,2})%\t([0-9]{1,3}[.][0-9]{1,2})%$/)
   {die();
   }
  else
   {
    if( $1>=$2 && ( $1 ne $2 || ( '99.99' ne $1 && '100.00' ne $1 ) ) )
     {die();
     }
    else
     {o($1,\$u);
      o($2,\$u);
     }
   }
 };
my $c='';
deflate(\$u => \$c,{Level=>9}) or die "gzip failed: $DeflateError\n";
print("\"".join("",map{sprintf("\\x%02X",$_);}unpack("C*",$c))."\"");

