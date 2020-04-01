

var f:text;
	n,k,i:longint;
begin
	assign(f,'gameseg.inp'); rewrite(f);
	randomize;
    k:= random(100000);
	n:=random(10000);
	writeln(f,n,' ',k);
	for i:= 1 to n do write(f,random(2*1000000000),' ');
	close(f);
end.
