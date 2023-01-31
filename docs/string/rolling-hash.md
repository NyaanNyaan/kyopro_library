## Rolling Hash

列の一致判定を前計算$\mathrm{O}(n)$クエリ$\mathrm{O}(1)$で処理するライブラリ。

#### 使い方

- `RollingHash<Str>(S)`: コンストラクタ。Sを対象としたRollingHashを構築する。$\mathrm{O}(\lvert S\rvert)$
- `build(S)`: Sを対象としたRollingHashを構築する。$\mathrm{O}(\lvert S\rvert)$
- `get(l, r)`: 区間[l, r)のハッシュを返す。$\mathrm{O}(1)$
- `get_hash(T)`: Tのハッシュ値を返す。$\mathrm{O}(\lvert T\rvert)$
- `find(T, lower = 0)`: Sのlower文字目以降で初めてTが出てくる位置を返す。(存在しない場合は-1を返す。)$\mathrm{O}(\lvert S\rvert)$
- `LCP(a, b, al, bl)`: aのal文字目から始まるsuffixとbのb文字目から始まるsuffixのLCPを返す。$\mathrm{O}(\log (\lvert S\rvert+\lvert T\rvert))$
- `strcmp(a, b, al, bl, ar=-1, br=-1)`: a[al, ar)とb[bl, br)の大小を比較する。(返り値はstd::strcmpの仕様に準ずる。)$\mathrm{O}(\log (\lvert S\rvert+\lvert T\rvert))$
- `size()`: Sのサイズを返す。
