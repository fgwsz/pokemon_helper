# Pokemon Helper 使用说明文档

## 1. 简介

Pokemon Helper 是一个宝可梦对战辅助工具,帮助玩家分析:

- **防御优势**:己方宝可梦的属性组合能够抵抗哪些攻击属性.
- **超级有效打击**:己方攻击招式属性对哪些防御属性造成 2 倍或 4 倍伤害.
- **弱点**:己方属性组合被哪些攻击属性克制.
- **打击盲点**:己方当前攻击属性组合无法造成 ≥1 倍伤害的防御属性.
- **推荐补充攻击类型**:在盲点较多时,推荐能够弥补盲点|同时自身弱点较少的攻击属性.

程序支持第 1 世代|第 2～5 世代|第 6 世代及以后的属性克制规则.

## 2. 快速开始

`Windows`操作系统:
```bash
./run-release.ps1
```
`Linux`操作系统:
```bash
./run-release.sh
```

根据提示依次输入:
1. 世代编号(≥1,大于 6 则按第 6 世代规则处理)
2. 己方宝可梦的自身属性(1 或 2 个)
3. 己方已拥有的攻击招式属性(1～4 个)

程序会输出分析结果,并询问是否继续分析其他组合.

## 3. 输入规则

### 3.1 世代编号
- 输入 `1` → 第 1 世代(15 种属性,无钢|恶|妖精)
- 输入 `2`～`5` → 第 2～5 世代(17 种属性,有钢|恶,无妖精)
- 输入 `6` 或更大 → 第 6 世代及以后(18 种属性,含妖精)

### 3.2 属性输入格式
使用**最短唯一前缀**或包含前缀的部分/完整名称(不区分大小写).支持前缀示例:

| 属性     | 前缀(可输入)          |
| -------- | ----------------------- |
| Bug      | `b`                     |
| Dark     | `da`                    |
| Dragon   | `dr`                    |
| Electric | `e`                     |
| Fairy    | `fa`(仅第 6 世代及以后)|
| Fighting | `fig`                   |
| Fire     | `fir`                   |
| Flying   | `fl`                    |
| Ghost    | `gh`                    |
| Grass    | `gra`                   |
| Ground   | `gro`                   |
| Ice      | `i`                     |
| Normal   | `n`                     |
| Poison   | `po`                    |
| Psychic  | `ps`                    |
| Rock     | `r`                     |
| Steel    | `s`                     |
| Water    | `w`                     |

多个属性用英文逗号分隔,例如:
- `b,da,dr` → Bug, Dark, Dragon
- `gra,s` → Grass, Steel
- `norm,po,ps` → Normal, Poison, Psychic

程序会显示解析后的属性集合,若输入无效则提示重新输入.

## 4. 输出解读

### 4.1 防御优势(Defensive advantages)
显示所有能对己方属性组合造成 **≤0.5 倍伤害**的攻击属性,以及具体倍率.

示例:
```
Defensive advantages: (
    [Normal, Poison, Rock, Ghost, Water, Grass, Electric, Psychic, Dragon, Steel, Dark],
    [`Normal->[Grass, Steel]:0.5`, `Poison->[Grass, Steel]:0`, ...]
)
```
- 第一项列表:抵抗/免疫的攻击属性.
- 第二项列表:每个攻击属性对防御组合的实际倍率(`0.5` 为减半,`0` 为免疫).

### 4.2 超级有效打击(Super effectives)
己方当前攻击属性对哪些防御属性造成 **≥2 倍**伤害.

示例:
```
Super effectives: (
    [Ground, Rock, Water, Grass, Ice],
    [`Grass->Ground:2`, `Grass->Rock:2`, `Steel->Rock:2`, ...]
)
```

### 4.3 弱点(Weaknesses)
己方属性组合被哪些攻击属性 **≥2 倍**克制.

示例:
```
Weaknesses: (
    [Fighting, Fire],
    [`Fighting->[Grass, Steel]:2`, `Fire->[Grass, Steel]:4`]
)
```
注意:如果某攻击属性造成 4 倍伤害(如 `Fire` 对 `Grass+Steel`),会显示为 `4`.

### 4.4 打击盲点(Coverage gaps)
己方当前攻击属性无法造成 ≥1 倍伤害的防御属性(即倍率为 0.5 或 0).

示例:
```
Coverage gaps: (
    Steel,
    [`Poison->Steel:0`, `Grass->Steel:0.5`, `Steel->Steel:0.5`]
)
```

### 4.5 推荐攻击类型(Top recommended attack types)
当存在盲点时,程序会评估所有可能的攻击属性(不包括已拥有的),并按以下准则排序:

1. **盲点数量**越少越好(首要指标).
2. **盲点中能打出超级有效的招式数量**越多越好(次要指标).
3. **自身弱点数量**越少越好(第三指标).
4. **自身弱点中能打出超级有效的招式数量**越多越好(第四指标).
5. 类型枚举值作为最终平局打破(数值越大排序越后,但通常无影响).

每个推荐条目包含:
- **coverage gaps**:该属性自身的攻击盲点(相对于原始目标盲点集合).
- **super matchups**:该属性对盲点造成的超级有效打击.
- **weaknesses**:该属性自身的弱点(从防御角度).
- **super matchups**:该属性对自身弱点的超级有效打击(表示反击能力).

示例:
```
1. Ground: {
    coverage gaps: Steel
    super matchups: `Ground->Steel:2`
    weaknesses: [Fighting, Fire]
    super matchups: `Ground->Fire:2`
}
```
表示推荐添加 **地面** 属性攻击,它能打击钢(超级有效),自身弱点为格斗|火,但对火属性招式能打出 2 倍伤害.

## 5. 完整运行示例

### 示例 1:草+钢宝可梦,已有草|钢|毒三种攻击招式

```
Please enter gen number(>=1,values>6 will use gen 6 rules).
Please enter number(unsigned long long)
> 2

Enter number is {2}.
Current gen: gen 2~5
Please enter pokemon owner type(s).
Enter types(comma-separated), using shortest unique prefixes:
    b[ug]        da[rk]      dr[agon]    e[lectric]  fig[hting]  fir[e]
    fl[ying]     gh[ost]     gra[ss]     gro[und]    i[ce]       n[ormal]
    po[ison]     ps[ychic]   r[ock]      s[teel]     w[ater]
Example: b,da,dr
> gra,s

Enter types is {[Grass, Steel]}.
Please enter pokemon attack type(s).
Enter types(comma-separated), using shortest unique prefixes:
    b[ug]        da[rk]      dr[agon]    e[lectric]  fig[hting]  fir[e]
    fl[ying]     gh[ost]     gra[ss]     gro[und]    i[ce]       n[ormal]
    po[ison]     ps[ychic]   r[ock]      s[teel]     w[ater]
Example: b,da,dr
> gra,s,po

Enter types is {[Poison, Grass, Steel]}.
Defensive advantages: (
    [Normal, Poison, Rock, Ghost, Water, Grass, Electric, Psychic, Dragon, Steel, Dark],
    [`Normal->[Grass, Steel]:0.5`, `Poison->[Grass, Steel]:0`, `Rock->[Grass, Steel]:0.5`, `Ghost->[Grass, Steel]:0.5`, `Water->[Grass, 
Steel]:0.5`, `Grass->[Grass, Steel]:0.25`, `Electric->[Grass, Steel]:0.5`, `Psychic->[Grass, Steel]:0.5`, `Dragon->[Grass, Steel]:0.5`, 
`Steel->[Grass, Steel]:0.5`, `Dark->[Grass, Steel]:0.5`]
)
Super effectives: (
    [Ground, Rock, Water, Grass, Ice],
    [`Grass->Ground:2`, `Grass->Rock:2`, `Steel->Rock:2`, `Grass->Water:2`, `Poison->Grass:2`, `Steel->Ice:2`]
)
Weaknesses: (
    [Fighting, Fire],
    [`Fighting->[Grass, Steel]:2`, `Fire->[Grass, Steel]:4`]
)
Coverage gaps: (
    Steel,
    [`Poison->Steel:0`, `Grass->Steel:0.5`, `Steel->Steel:0.5`]
)
Top recommended attack types:
1. Ground: {
    coverage gaps: Steel
    super matchups: `Ground->Steel:2`
    weaknesses: [Fighting, Fire]
    super matchups: `Ground->Fire:2`
}
2. Fighting: {
    coverage gaps: Steel
    super matchups: `Fighting->Steel:2`
    weaknesses: [Fighting, Fire]
}
3. Fire: {
    coverage gaps: Steel
    super matchups: `Fire->Steel:2`
    weaknesses: Fighting
}
4. Water: {
    coverage gaps: Steel
    weaknesses: [Fighting, Fire]
    super matchups: `Water->Fire:2`
}
5. Electric: {
    coverage gaps: Steel
    weaknesses: [Fighting, Fire]
}
```

分析结果:
- 防御优势:抵抗 11 种属性,免疫毒.
- 超级有效:地面|岩石|水|草|冰.
- 弱点:格斗(2 倍)|火(4 倍).
- 盲点:钢(草和毒都无效或减半).
- 推荐前几名:地面|格斗|火|水|电.

### 示例 2:龙+恶宝可梦,已有普通|龙|恶三种攻击招式

```
Please enter gen number(>=1,values>6 will use gen 6 rules).
Please enter number(unsigned long long)
> 5

Enter number is {5}.
Current gen: gen 2~5
Please enter pokemon owner type(s).
Enter types(comma-separated), using shortest unique prefixes:
    b[ug]        da[rk]      dr[agon]    e[lectric]  fig[hting]  fir[e]
    fl[ying]     gh[ost]     gra[ss]     gro[und]    i[ce]       n[ormal]
    po[ison]     ps[ychic]   r[ock]      s[teel]     w[ater]
Example: b,da,dr
> dab,dr
Invalid input(invalid type name: dab), please try again.
Please enter pokemon owner type(s).
Enter types(comma-separated), using shortest unique prefixes:
    b[ug]        da[rk]      dr[agon]    e[lectric]  fig[hting]  fir[e]
    fl[ying]     gh[ost]     gra[ss]     gro[und]    i[ce]       n[ormal]
    po[ison]     ps[ychic]   r[ock]      s[teel]     w[ater]
Example: b,da,dr
> da,drag

Enter types is {[Dragon, Dark]}.
Please enter pokemon attack type(s).
Enter types(comma-separated), using shortest unique prefixes:
    b[ug]        da[rk]      dr[agon]    e[lectric]  fig[hting]  fir[e]
    fl[ying]     gh[ost]     gra[ss]     gro[und]    i[ce]       n[ormal]
    po[ison]     ps[ychic]   r[ock]      s[teel]     w[ater]
Example: b,da,dr
> da,dra,n

Enter types is {[Normal, Dragon, Dark]}.
Defensive advantages: (
    [Ghost, Fire, Water, Grass, Electric, Psychic, Dark],
    [`Ghost->[Dragon, Dark]:0.5`, `Fire->[Dragon, Dark]:0.5`, `Water->[Dragon, Dark]:0.5`, `Grass->[Dragon, Dark]:0.5`, `Electric->[Drag
on, Dark]:0.5`, `Psychic->[Dragon, Dark]:0`, `Dark->[Dragon, Dark]:0.5`]
)
Super effectives: (
    [Ghost, Psychic, Dragon],
    [`Dark->Ghost:2`, `Dark->Psychic:2`, `Dragon->Dragon:2`]
)
Weaknesses: (
    [Fighting, Bug, Ice, Dragon],
    [`Fighting->[Dragon, Dark]:2`, `Bug->[Dragon, Dark]:2`, `Ice->[Dragon, Dark]:2`, `Dragon->[Dragon, Dark]:2`]
)
Coverage gaps: (
    Steel,
    [`Normal->Steel:0.5`, `Dragon->Steel:0.5`, `Dark->Steel:0.5`]
)
Top recommended attack types:
1. Fire: {
    coverage gaps: Steel
    super matchups: `Fire->Steel:2`
    weaknesses: [Fighting, Bug, Ice]
    super matchups: [`Fire->Bug:2`, `Fire->Ice:2`]
}
2. Fighting: {
    coverage gaps: Steel
    super matchups: `Fighting->Steel:2`
    weaknesses: [Fighting, Ice, Dragon]
    super matchups: `Fighting->Ice:2`
}
3. Ground: {
    coverage gaps: Steel
    super matchups: `Ground->Steel:2`
    weaknesses: [Fighting, Ice, Dragon]
}
4. Electric: {
    coverage gaps: Steel
    weaknesses: [Fighting, Bug, Ice]
}
5. Water: {
    coverage gaps: Steel
    weaknesses: [Fighting, Bug, Ice]
}
```

分析结果:
- 防御优势:抵抗幽灵|火|水|草|电|超能(免疫)|恶.
- 超级有效:幽灵|超能|龙.
- 弱点:格斗|虫|冰|龙.
- 盲点:钢.
- 推荐前几名:火|格斗|地面|电|水.

## 6. 注意事项

- 第 1 世代没有钢|恶|妖精属性,输入时会自动校验.
- 输入的攻击招式属性数量建议 ≤4.
- 推荐算法仅基于单属性盲点分析,不直接模拟双属性防御方的组合效果.
- 若当前攻击组合已无盲点(`Coverage gaps` 为空),则不会显示推荐列表.

## 7. 错误处理

常见输入错误及提示:
- 输入无法识别的类型名(如 `dab`) → `Invalid type name: xxx`
- 输入属性不在当前世代存在(如第一世代输入 `s` 代表钢) → 提示不存在,重新输入.
- 世代编号 <1 → 提示要求 ≥1.
- 属性数量不符合预期(如自身属性不是 1 或 2 个) → 提示重新输入.

## 8. 退出程序

在每次分析结束后,程序询问:
```
Do you want to continue?(y/n)
```
输入 `y` 或 `Y` 开始新一轮分析,输入其他字符则退出.

---

*文档版本 1.0*  
*基于 Pokemon Helper 实际运行日志编写*
