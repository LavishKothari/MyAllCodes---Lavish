n,k=map(int,raw_input().split())
m=map(int,raw_input().split())
a=[0]*(1<<20)
o=0
for i in range(0,n):o+=2*a[m[i]%k];a[m[i]%k]+=1
print o






@q=split(' ',<>);
$n=@q[0];
@a=split(' ',<>);
@r=(0)*@q[1];
while($n--){
	$t=$a[$i++%@q[1]];
    $o+=$r[$t]*2;
    $r[$t]++;
}
print$o