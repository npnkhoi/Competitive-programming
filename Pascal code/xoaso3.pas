uses math;
const fin='';
    fon='';
	nmax=trunc(1e5)+7;
var fi,fo:text;
	n:ansistring;
	sau,truoc:array[0..nmax] of longint;
	k,l,i,mark,duong,count:longint;
procedure input;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
	readln(fi,l,k);
	readln(fi,n);
end;
function cl(vt:longint):longint;
begin
	exit(ord(n[sau[vt]])-ord(n[vt]));
end;

procedure init;
begin
	//l:= length(n);
    for i:= 1 to l do
    begin
		truoc[i]:= i-1;
		sau[i]:=i+1;
	end;
	duong:= 0;
	for i:= 1 to l-1 do if cl(i)>0 then inc(duong);

end;

procedure main;
begin
	if duong>0 then mark:= 1 else mark:= l;
	for i:= 1 to k do
	begin
		if duong>0 then
			begin
				while (cl(mark)<=0) do mark:=sau[mark];
				n[mark]:='.';
                truoc[sau[mark]]:=truoc[mark];
                sau[truoc[mark]]:=sau[mark];
                mark:=sau[mark];
                dec(duong);
				if (truoc[mark]>0) and (cl(mark-1)>0) then
                begin
                    mark:=truoc[mark];
                    inc(duong);
                end;
			end
		{else
			delete(n,length(n),1);}
	end;
end;
procedure output;
begin
	count:= 0;
	for i:= 1 to l do
		begin
			if n[i]<>'.' then
            begin
                write(fo,n[i]);
			    inc(count);
            end;
			if count=l-k then break;
		end;
	close(fi); close(fo);
end;
begin
	input;
	init;
	main;
	output;
end.
