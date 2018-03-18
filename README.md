# mruby-capacity   [![Build Status](https://travis-ci.org/pyama86/mruby-capacity.svg?branch=master)](https://travis-ci.org/pyama86/mruby-capacity)

Provides interface method of capacity of String class and array class.

## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'pyama86/mruby-capacity'
end
```
## example
```ruby
s = "example"
s.capacity
=> 23
s.capacity = 100
=> 100
```

## License
under the MIT License:
- see LICENSE file
