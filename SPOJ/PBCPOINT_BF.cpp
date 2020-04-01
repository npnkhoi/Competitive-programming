program PUNCTE_AnhDuc;
uses    math;
const   maxv=1111;
        fi='';
        fo='';
        oo=trunc(1e9);
type    e=record
        x,y:longint;
        end;
var     q:array[1..4*maxv*maxv] of e;
        red:array[-maxv..maxv,-maxv..maxv] of boolean;
        maR,miR,maC,miC:array[-maxv..maxv] of longint;
        l,r,i,j,res,minx,miny,maxx,maxy,x,y:longint;
        u:e;
        inp,oup:text;

procedure push(x,y:longint);
begin
        red[x,y]:=true;
        inc(r);
        q[r].x:=x;
        q[r].y:=y;
        miR[x]:=min(miR[x],y);
        maR[x]:=max(maR[x],y);
        miC[y]:=min(miC[y],x);
        maC[y]:=max(maC[y],x);
end;

begin
        assign(inp,fi);reset(inp);
        assign(oup,fo);rewrite(oup);
        readln(inp,r);l:=1;
        for i:=1 to r do begin
                readln(inp,q[i].x,q[i].y);
                red[q[i].x,q[i].y]:=true;
                minx:=min(minx,q[i].x);miny:=min(miny,q[i].y);
                maxx:=max(maxx,q[i].x);maxy:=max(maxy,q[i].y);
        end;
        for i:=minx to maxx do miR[i]:=oo;
        for i:=minx to maxx do maR[i]:=-oo;
        for i:=miny to maxy do miC[i]:=oo;
        for i:=miny to maxy do maC[i]:=-oo;
        for i:=1 to r do begin
                x:=q[i].x;y:=q[i].y;
                miR[x]:=min(miR[x],y);
                maR[x]:=max(maR[x],y);
                miC[y]:=min(miC[y],x);
                maC[y]:=max(maC[y],x);
        end;
        while l<=r do begin
                u:=q[l];inc(l);
                if (u.x=miC[u.y]) or (u.x=maC[u.y]) then begin
                        for x:=miC[u.y] to maC[u.y] do
                        if not red[x,u.y] then push(x,u.y);
                end;
                if (u.y=miR[u.x]) or (u.y=maR[u.x]) then begin
                        for y:=miR[u.x] to maR[u.x] do
                        if not red[u.x,y] then push(u.x,y);
                end;
        end;
        for i:=minx to maxx do
        for j:=miny to maxy do
        if red[i,j] then inc(res);
        write(oup,res);close(oup);
end.
