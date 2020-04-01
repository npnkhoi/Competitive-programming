uses math;
type bang=record
    fi:int64; se:longint; end;
const smax=trunc(1e5)+1;
var fi,fo:text;
    a:array[0..100003] of longint;
    s:array[0..100003] of bang;
    n,k,i,j,foot,head,dau,cuoi:longint;
    tmp:int64;
procedure start;
begin
    assign(fi,'road.inp'); reset(fi);
    assign(fo,'road.out'); rewrite(fo);
    readln(fi,n,k);
    for i:= 1 to n do readln(fi,a[i]);
    s[0].fi:= 0;
    for i:= 1 to n do
        s[i].fi:=s[i-1].fi+a[i]-k;
    for i:= 1 to n do s[i].se:= i;
end;
procedure sort(l,r:longint);
var i,j,mid:int64;
    tmp:bang;
begin
    i:= l; j:= r; mid:= s[(l+r) div 2].fi;
    repeat
        while s[i].fi<mid do inc(i);
        while mid<s[j].fi do dec(j);
        if i<=j then
        begin
            tmp:= s[i]; s[i]:= s[j]; s[j]:= tmp;
            inc(i); dec(j);
        end;
    until i>j;
    if i<r then sort(i,r);
    if l<j then sort(l,j);
end;
procedure main;
begin
    dau:= smax; cuoi:= 0;
    head:= smax; foot:= 0;
    for i:= 1 to n do
    begin
        if tmp<>s[i].fi then
        begin
            tmp:= s[i].fi;
            dau:= smax;
            cuoi:= 0;
        end;
        dau:= min(dau,s[i].se);
        cuoi:= max(cuoi,s[i].se);
        if (cuoi-dau>foot-head) or ((cuoi-dau=foot-head) and (dau<head))
        then begin head:= dau; foot:= cuoi; end;
    end;
end;
begin
    start;
    sort(1,n);
    main;
    if foot-head>0 then writeln(fo,head+1,' ',foot-head)
    else writeln(fo,0);
    close(fi); close(fo);
end.