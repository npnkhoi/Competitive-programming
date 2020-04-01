uses math;
const fin='hoanvi.inp';
	fon='';
var fi,fo:text;
    a,b:array[0..20] of longint;
    ok:array[0..200] of boolean;
    hieu:array[0..200] of longint;
    n,i,count:longint;
procedure input;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
    readln(fi,n);
    for i:= 1 to n do read(fi,a[i]);
    b[0]:= 0;
end;
function check(j,i:longint):boolean;
var t:longint;
begin
    if ok[a[j]]=false then exit(false);
    if hieu[a[j]]>0 then exit(false);
    exit(true);
end;
procedure thongbao;
var i:longint;
begin
    for i:= 1 to n do write(fo,b[i],' ');
    writeln; inc(count)
end;
procedure try(i:longint);
var j,k:longint;
begin
    for j:= 1 to n do if check(j,i) then
    begin
        b[i]:= a[j];
        ok[a[j]]:= false;
        for k:= 1 to i-1 do
            if 2*b[i]-b[k]>0 then inc(hieu[2*b[i]-b[k]]);
        if i=n then thongbao else try(i+1);
        ok[a[j]]:= true;
        for k:= 1 to i-1 do
            if 2*b[i]-b[k]>0 then dec(hieu[2*b[i]-b[k]]);
    end;
end;
procedure main;
begin
    fillchar(ok,sizeof(ok),true);
    fillchar(hieu,sizeof(hieu),0);
    count:= 0;
    try(1);
end;
procedure output;
begin
    writeln(fo,count);
	close(fi); close(fo);
end;
begin
    input;
    main;
    output;
end.