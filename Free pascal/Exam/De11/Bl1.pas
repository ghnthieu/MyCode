Program sodacbiet;
var n:integer;
function kt(n:integer):boolean;
var tong,tich:longint;
begin
  tong:=0;
  tich:=1;
  while n<>0 do
    begin
      tong:=tong+n mod 10;
      tich:=tich*n mod 10;
      n:=n div 10;
    end;
  if tong<>tich then
    exit(false);
  exit(true);
end;
procedure xuly;
var fi,fo:text;
    i:integer;
begin
  assign(fi,'dulieu.inp');reset(fi);
  assign(fo,'ketqua.out');rewrite(fo);
  read(fi,n);
  i:=n-1;
  repeat
    inc(i);
  until kt(i);
  if i>9999 then
    write(fo,'0')
  else
    write(fo,i);
  close(fi);
  close(fo);
end;
Begin
  xuly;
End.
