#include "SSRThread.hpp"
#include "shadowsocks.h"
namespace Qv2ray::core::kernel
{
SSRThread::SSRThread(){}
SSRThread::SSRThread(int localPort,
                     int remotePort,
                     std::string local_addr,
                     std::string remote_host,
                     std::string method,
                     std::string password,
                     std::string obfs,
                     std::string obfs_param,
                     std::string protocol,
                     std::string protocol_param,
                     QString inboundTag):
      localPort(localPort),
      remotePort(remotePort),
      local_addr(local_addr),
      remote_host(remote_host),
      method(method),
      password(password),
      obfs(obfs),
      obfs_param(obfs_param),
      protocol(protocol),
      protocol_param(protocol_param),
      inboundTag(inboundTag)
{

}
QString SSRThread::getInboundTag()
{
    return inboundTag;
}
void SSRThread::run()
{
    profile_t profile;
    profile.remote_host=remote_host.data();
    profile.local_addr=local_addr.empty()? NULL:local_addr.data();
    profile.method=method.data();
    profile.timeout=600;
    profile.password=password.data();
    profile.obfs=obfs.data();
    profile.obfs_param=obfs_param.data();
    profile.protocol=protocol.data();
    profile.protocol_param=protocol_param.data();
    profile.remote_port=remotePort;
    profile.local_port=localPort;
    profile.mtu=0;//we don't use udp relay, therefore we set mtu to zero.
    profile.mode=0;//we don't use udp relay, therefore we set mode to zero.
    profile.acl=NULL;
    profile.log=NULL;
    profile.fast_open=1;
    profile.mptcp=0;
    start_ss_local_server(profile);
}
SSRThread::~SSRThread()
{
    if(isRunning())
    {
        stop_ss_local_server();
        wait();
    }
}
}
