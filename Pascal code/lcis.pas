uses crt, math;
const
        tfi     =       '';
        tfo     =       '';
        maxn    =       500;
var
        a,b,g : array[1..maxn] of longint;
        f : array[1..maxn,1..maxn] of longint;
        n,m,res : longint;
        fi,fo : text;

procedure progress;
var
        i,j,tg : longint;
begin
        readln(fi,n);
        for i:=1 to n do read(fi,a[i]);
        readln(fi,m);
        for i:=1 to m do read(fi,b[i]);
        for i:=1 to n do
         begin
             tg:=0;
             for j:=1 to m do
              begin
                  if a[i] = b[j] then f[i,j]:=tg + 1;
                  if b[j] < a[i] then tg:=max(tg,g[j]);
              end;
             for j:=1 to m do g[j]:=max(g[j],f[i,j]);
         end;
        res:=0;
        for i:=1 to n do
         for j:=1 to m do
          res:=max(res,f[i,j]);
        writeln(fo,res);
end;

begin
        assign(fi,tfi); reset(fi);
        assign(fo,tfo); rewrite(fo);
        progress;
        close(fi);
        close(fo);
end.
