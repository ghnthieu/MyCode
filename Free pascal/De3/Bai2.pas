Program bai2;
var fi,fo:text;
procedure nhap(var fi:text);
begin
  assign(fi,'nto.inp');reset(fi);
end;
function kt(n:word):boolean;
var ok:boolean;
    i:word;
begin
  ok:=true;
  if n<2 then
    ok:=false
  else
    for i:=2 to trunc(sqrt(n)) do
      if n mod i=0 then
        begin
          ok:=false;
          break;
        end;
  kt:=ok;
end;
procedure xuly(var fo:text);
begin
  assign(fo,'nto.out');rewrite(fo);
  read(fi,n);
  for i:=2 to n do
    if kt(i) then
      write(fo,i,' ');
  close(fo);
  close(fi);
end;
Begin
  nhap(fi);
  xuly(fo);
End.
