var     stp3,stp2:array[0..500] of ansistring;
        i,m,n,max,e:integer;
        s1,s2,s3,s4:ansistring;
		st:string;
        f,fo:text;
function sum(a,b:ansistring):ansistring;
var rem,x:byte;
    i:integer;
	tmp,s:ansistring;
begin
	rem:= 0; s:='';
	if length(a)<length(b) then
	begin
		tmp:= a;
		a:= b;
		b:= tmp;
	end;
    for i:= 1 to length(a)-length(b) do b:='0'+b;
	for i:= length(a) downto 1 do
	begin
		x:= ord(a[i])+ord(b[i])+rem-96;
		rem:= x div 10;
		s:= chr(x mod 10+48)+s;
	end;
	if rem=1 then s:='1'+s;
	exit(s);
end;
function pro0(a:ansistring;b:char):ansistring;
var rem,x,i:byte;
	s:ansistring;
begin
	rem:= 0;
	for i:= length(a) downto 1 do
	begin
		x:= (ord(a[i])-48)*(ord(b)-48)+rem;
		rem:= x div 10;
		s:= chr(x mod 10 + 48)+s;
	end;
	if rem>0 then s:= chr(rem+48)+s;
	exit(s);
end;
function pro(a,b:ansistring):ansistring;
var s:ansistring;
	i,j:integer;
	tmp:ansistring;
begin
	s:= '';
	for i:= length(b) downto 1 do
	begin
		tmp:= pro0(a,b[i]);
		for j:= 1 to length(b)-i do tmp:= tmp+'0';
		s:= sum(s,tmp);
	end;
	exit(s);
end;
begin
        assign(f,'chutieu.inp'); reset(f);
        assign(fo,'chutieu.out'); rewrite(fo);
        while true do
        begin
        readln(f,st);
		if st='' then break else
		begin
		val(copy(st,1,pos(' ',st)-1),m,e);
		val(copy(st,pos(' ',st)+1,length(st)-pos(' ',st)),n,e);
        if m>n then max:= m else max:= n;
        /////////////////////////////
        stp3[1]:= '1';
        stp3[2]:= '2';
        stp3[3]:= '4';
        for i:= 4 to max do
            stp3[i]:=sum(stp3[i-1],sum(stp3[i-2],stp3[i-3]));
        ////////////////////////////
        stp2[0]:= '1';
        stp2[1]:= '1';
        stp2[2]:= '2';
        for i:= 3 to max do stp2[i]:=sum(stp2[i-1],stp2[i-2]);
        ////////////////////////////
        s1:= stp3[m];
        s2:= stp3[n];
        s3:= '0';
        for i:= 1 to n-2 do
            s3:=sum(s3,pro(stp2[i-1],stp2[n-i-2]));
        s4:= stp2[m];
        writeln(pro(pro(s1,s2),pro(s3,s4)));
		end;
        end;
        close(f); close(fo);
end.
