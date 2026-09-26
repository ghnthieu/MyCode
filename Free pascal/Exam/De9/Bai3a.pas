Program bl3;
var n:longint;
function kt1(s:string):boolean;
var ok:boolean;
begin
  if s[1]='1' then
    ok:=true
  else
    ok:=false;
  kt1:=ok;
end;
function kt2(s:string):boolean;
var ok:boolean;
    i:byte;
begin
  for i:=2 to length(s) do
    if (s[i]='1') or (s[i]='4') then
      ok:=true
    else
      begin
        ok:=false;
        break;
      end;
  kt2:=ok;
end;
function kt3(s:string):boolean;
var ok:boolean;
    i:byte;
begin
  ok:=true;
  for i:=2 to length(s)-2 do
    if (s[i]='4') and (s[i+1]='4') and (s[i+2]='4') then
      ok:=false;
  kt3:=ok;
end;
procedure xuly;
var fi,fo:text;
    s:string;
    i:byte;
begin
  assign(fi,'bl3a.inp');reset(fi);
  assign(fo,'bl3a.out');rewrite(fo);
  read(fi,n);
  str(n,s);
  if (kt1(s)) and (kt2(s)) and (kt3(s)) then
    write(fo,'YES')
  else
    write(fo,'NO');
  close(fi);
  close(fo);
end;
Begin
  xuly;
End.
