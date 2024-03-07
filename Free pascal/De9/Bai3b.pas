Program bl3;
var n:longint;
procedure xuly;
var fi,fo:text;
    i:byte;
    s:string;
begin
  assign(fi,'bl3b.inp');reset(fi);
  assign(fo,'bl3b.out');rewrite(fo);
  read(fi,n);
  str(n,s);
  i:=length(s);
  while true do
    begin
    if i=0 then
      break;
    if (i>=3) and (s[i-2]+s[i-1]+s[i]='144') then
      begin
        i:=i-3;
        continue;
      end;
    if (i>=2) and (s[i-1]+s[i]='14') then
      begin
        i:=i-2;
        continue;
      end;
    if (i>=1) and (s[i]='1') then
      begin
        i:=i-1;
        continue;
      end;
    write(fo,'NO');
    close(fo);
    exit;
  end;
  writeln(fo,'YES');
  close(fi);
  close(fo);

end;
Begin
  xuly;
End.

