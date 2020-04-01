var a,b:longint;
begin
	readln(a,b);
	if a=1 then a:= 14;
	if b=1 then b:= 14;
	if a>b then writeln('Khang')
		else if a<b then writeln('Khoi')
			else writeln('Draw');
end.