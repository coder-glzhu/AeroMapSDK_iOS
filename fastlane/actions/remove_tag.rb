module Fastlane
  module Actions

    class RemoveTagAction < Action
      def self.run(params)

        commonds = []
        if params[:dL]
            commonds << "git tag -d #{params[:tagName]}"
        end

        if params[:dR]
            commonds << "git push origin :#{params[:tagName]}"
        end

        result = Actions.sh(commonds.join(' & '))

        return result


    end

      #####################################################
      # @!group Documentation
      #####################################################

      def self.description
        "删除标签"
      end

      def self.details
        "git tag -d xxx  &  git push orgin :xxx"
      end

      def self.available_options
        [
          FastlaneCore::ConfigItem.new(key: :tagName,
                                       env_name: 'TAG_NAME',
                                       description: "需要删除的标签名称",
                                       optional: false,
                                       is_string: true),
          FastlaneCore::ConfigItem.new(key: :dR,
                                       env_name: 'DEL_REMOTE',
                                       description: "是否删除远程标签",
                                       optional: true,
                                       is_string: false,
                                       default_value: false),
          FastlaneCore::ConfigItem.new(key: :dL,
                                       env_name: 'DEL_LOCAL',
                                       description: "是否删除本地标签",
                                       optional: true,
                                       is_string: false,
                                       default_value: false)
        ]
      end

      def self.output

      end

      def self.return_value
        nil
      end

      def self.authors
        ["🐷🐷>>>小菜猪"]
      end


      def self.is_supported?(platform)
        # you can do things like
        # 
        #  true
        # 
        #  platform == :ios
        # 
        #  [:ios, :mac].include?(platform)
        # 

        platform == :ios
      end
    end
  end
end
