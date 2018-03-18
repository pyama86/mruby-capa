# mruby-capacity   [![Build Status](https://travis-ci.org/pyama86/mruby-capacity.svg?branch=master)](https://travis-ci.org/pyama86/mruby-capacity)
Capacity class
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
p Capacity.hi
#=> "hi!!"
t = Capacity.new "hello"
p t.hello
#=> "hello"
p t.bye
#=> "hello bye"
```

## License
under the MIT License:
- see LICENSE file
