import sys

metrics = {
  'ATK': 0,
  'Crit Rate': 5,
  'Crit DMG Rate': 50
}

# sys.stdin = open('D.inp', 'r')

for i in range(5):
  for j in range(5):
    typename, x = input().split('+')
    # print('adding', typename, x)
    x = x.strip('%')
    # print('adding', typename, x)
    metrics.setdefault(typename, 0)
    metrics[typename] += float(x)

# print(metrics)

metrics['Crit Rate'] = min(metrics['Crit Rate'], 100)
metrics['ATK'] = 1500 * (1 + metrics['ATK Rate']/100) + metrics['ATK']
e = metrics['ATK'] * (1 - (metrics['Crit Rate']/100)) + metrics['ATK'] * (1 + (metrics['Crit DMG Rate']/100)) * (metrics['Crit Rate']/100)
# print(e)
print('{:.10f}'.format(e))

